#ifndef NUMERICAL_METHODS
#define NUMERICAL_METHODS
#include <complex.h> 
#include "Utils.cpp"


class GrossPitaevski{
    private:
        Utils utils;
        const std::complex<double> i = std::complex<double>(0, 1);

    public:
        std::complex<double> getPsiXSubstep(std::complex<double> PsiC[], std::complex<double> PsiX[], double t);
        std::complex<double>* getPsiCSubstep(std::complex<double> PsiC[], std::complex<double> PsiX[], double t);
        std::complex<double> getRungeKutta();
};

#endif /* NUMERICAL_METHODS */