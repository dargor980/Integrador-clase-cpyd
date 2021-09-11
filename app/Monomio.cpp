#include "Monomio.h"

Monomio::Monomio(){
    this->coeficiente = 0.0;
    this->grado = 0;
}

Monomio::Monomio(const Monomio& orig){
    this->coeficiente = orig.coeficiente;
    this->grado = orig.grado;
}

Monomio::~Monomio(){
}

double Monomio::GetCoeficiente(){
    return coeficiente;
}

void Monomio::SetCoeficiente(double coeficiente){
    this->coeficiente = coeficiente;
}

int Monomio::GetGrado(){
    return grado;
}

void Monomio::SetGrado(int grado){
    this->grado = grado;
}

std::string Monomio::toString(){
    std::stringstream ss;
    ss << " [" << coeficiente << "]x**[" << grado << "] ";
    return ss.str();
}