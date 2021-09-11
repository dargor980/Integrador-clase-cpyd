#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <omp.h>

#include "Monomio.h"

/**
 * Esta función elimina los espacios que se reciben en el texto
 * @param texto El texto a procesar (Ej: "3**3 + 2")
 * @return El mismo texto sin espacio (Ej: "3x**3+2")
 * */
std::string quitar_espacios(std::string texto);


/**
 * 
 * @param polinomioStr una cadena de monomios
 * @return Un vector de monomios (como cadena de texto) tokenizados por el caracter '+
 * */
std::vector<std::string> obtener_terminos(std::string polinomioStr);

/**
 * 
 * @param texto Texto a ser procesado en la forma de [coeficiente]**[grado]
 * @return El monomio asociado
 * */
Monomio str2Mono(std::string texto);


/**
 * 
 * @param polinomioStr Cadena de caracteres con los polinomios
 * @return vector de objetos monomios
 * */
std::vector<Monomio> convertir(std::string polinomioStr);


/**
 * 
 * @param polinomio Vector con los monomios resultantes del proceso
 * @param inferior Cota inferior para el cálculo
 * @param superior cota superior para el cálculo
 * @return Resultado de la evaluación polinómimca
 * */
double integrar_evaluar(std::vector<Monomio> polinomio, int inferior, int superior);

#endif /* UTILS_H*/