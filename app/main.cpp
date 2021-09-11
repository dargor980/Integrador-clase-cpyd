#include <iostream>
#include "utils.h"

int main(int argc, char** argv){
    if(argc < 4){
        std::cout << std::endl << "Argumentos inválidos" << std::endl;
        std::cout << std::endl << argv[0] << "\"[polinomio]\" [limite inferio] [limite superior]" << std::endl;
        return 1;
    }

    std::string polinomioStr(argv[1]);
    std::vector<Monomio> polinomio = convertir(polinomioStr);
    int inferior = atoi(argv[2]);
    int superior = atoi(argv[3]);

    double resultado = integrar_evaluar(polinomio, inferior, superior);
    std::cout << std::endl << argv[0] << " \"" << polinomioStr << "\"" << inferior << " " << superior << "= " << resultado << std::endl;

    return 0;
}