#ifndef MONOMIO_H
#define MONOMIO_H

#include <sstream>

/**
 * 
 * 
 * */
class Monomio {
    public:
        /**
         * Constructor por defecto
         * */
        Monomio();

        /**
         * Constructor por copia
         * @param orig monomio original
         * */
        Monomio(const Monomio& orig);

        /**
         * Destructor por defecto.
         * */
        virtual ~Monomio();

        /**
         * @return El coeficiente del monomio.
         * */
        double GetCoeficiente();

        /**
         * Setea el coeficiente del monomio.
         * @param coeficiente El coeficiente del monomio.
         * */
        void SetCoeficiente(double coeficiente);

        /**
         * @return El grado del monomio
         * */
        int GetGrado();

        /**
         * Setea el grado del monomio.
         * @param grado El grado del monomio.
         * */
        void SetGrado(int grado);

        std::string toString();
private:
        double coeficiente;
        int grado;
};

#endif /* MONOMIO_H */