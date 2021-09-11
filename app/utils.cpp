#include "utils.h"
#include <string>

std::string quitar_espacios(std::string texto){
    std::string str = texto;

    std::string::iterator it = std::remove(str.begin(), str.end(), ' ');
    str.erase(it, str.end());

    return str;
}

std::vector<std::string> obtener_terminos(std::string polinomioStr){
    std::vector<std::string> elementos;
    if(!polinomioStr.empty()){
        char* strArray = new char[polinomioStr.size() + 1];
        strncpy(strArray, polinomioStr.c_str(), polinomioStr.size());
        char* token = strtok(strArray, "+-");
        while(token != NULL){
            std::string elemento(token);
            elementos.push_back(elemento);
            token = strtok(NULL, "+-");
        }
        delete strArray;
    }
    return elementos;
}

Monomio str2Mono(std::string texto){
    Monomio mono;
    if(!texto.empty()){
        std::string str = texto;
        unsigned int indice = str.find("x**");
        if(indice > 0){
            std::string coefStr = str.substr(0, indice);
            mono.SetCoeficiente(atof(coefStr.c_str()));

            unsigned int resto = indice + 3;
            if(str.size() >= resto){
                std::string gradoStr = str.substr(resto, str.size() - 1);
                mono.SetGrado(atoi(gradoStr.c_str()));
            } else{
                mono.SetGrado(0);
            }
        } else{
            mono.SetCoeficiente(1.0);
            std::string gradoStr = str.substr(indice + 3, str.size() - 1);
            if(!gradoStr.empty()){
                mono.SetGrado(atoi(gradoStr.c_str()));
            } else{
                mono.SetGrado(0);
            }
        }
    }
    return mono;
}

std::vector<Monomio> convertir(std::string polinomioStr){
    std::vector<Monomio> polinomio;
    if(!polinomioStr.empty()){
        std::string resultado = quitar_espacios(polinomioStr);
        std::vector<std::string> terminos = obtener_terminos(resultado);

        if(terminos.size() > (long unsigned int) omp_get_num_threads()){
#pragma omp parallel
            {
                std::vector<int>::size_type i = 0;

#pragma omp parallel for private(i)
                for(i = 0; i < terminos.size(); i++){
                    std::string valor = terminos[i];
                    Monomio mono = str2Mono(valor);
#pragma omp critical
                    polinomio.push_back(mono);

                }
            }

        } else if(terminos.size() > 0 && terminos.size() <= (long unsigned int) omp_get_num_threads()){
            std::vector<std::string>::size_type i = 0;
            for(i = 0; i < terminos.size(); i ++){
                std::string valor = terminos[i];
                Monomio mono = str2Mono(valor);
                polinomio.push_back(mono);
            }
        } else{
            std::cerr << "No se pudo procesar el polinomio " << polinomioStr << std::endl;
        }
    }
    return polinomio;
}


double integrar_evaluar(std::vector<Monomio> polinomio, int inferior, int superior){
    
    double suma = (double) 0;

    if(polinomio.size() > (long unsigned int) omp_get_num_threads()){
#pragma omp parallel
        {
            std::vector<Monomio>::size_type i;

#pragma omp parallel for private(i)
            for(i = 0; i < polinomio.size(); i++){
                Monomio monomio = polinomio[i];
                Monomio integrado;
                integrado.SetCoeficiente(monomio.GetCoeficiente() / (monomio.GetGrado() + 1));
                integrado.SetGrado(monomio.GetGrado() + 1);

#pragma omp critical
                {
                    double arriba = (integrado.GetCoeficiente() * powf(superior, integrado.GetGrado()));
                    double abajo = (integrado.GetCoeficiente() * powf(inferior, integrado.GetGrado()));

                    suma += (arriba - abajo);
                }
            }
        }
    } else{
        std::vector<Monomio>::size_type i;
        for (i = 0; i < polinomio.size(); i++){
            Monomio monomio = polinomio[i];
            Monomio integrado;
            integrado.SetCoeficiente(monomio.GetCoeficiente() / (monomio.GetGrado() + 1));
            integrado.SetGrado(monomio.GetGrado() + 1);

            double arriba = (integrado.GetCoeficiente()* powf(superior, integrado.GetGrado()));
            double abajo = (integrado.GetCoeficiente() * powf(inferior, integrado.GetGrado()));
            suma += (arriba- abajo); 
        }
    }
    return suma;
}