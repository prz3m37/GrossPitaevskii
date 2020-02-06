#ifndef NUMERICAL_METHODS
#define NUMERICAL_METHODS
#include <complex.h> 
#include "Utils.cpp"

class GrossPitaevski{
    friend class ResultProvider;

    private:
        Utils utils;

        const std::complex<double> i = std::complex<double>(0, 1);
        std::complex<double> *getPsiXSubstep(std::complex<double> PsiC[], std::complex<double> PsiX[], double t);
        std::complex<double> *getPsiCSubstep(std::complex<double> PsiC[], std::complex<double> PsiX[], double t);
        std::complex<double> *incerementTimestep(std::complex<double> PsiC[], std::complex<double> PsiX[], double t);
        
        public:
            void getRungeKutta(std::complex<double> PsiC[], std::complex<double> PsiX[], double t, double dt);
};

#endif /* NUMERICAL_METHODS */