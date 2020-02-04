#ifndef NUMERICAL_METHODS
#define NUMERICAL_METHODS
#include <complex.h> 

class NumericalMethods{
    public:
        std::complex<double> getLaplace();
        std::complex<double> getRungeKutta();
};

#endif /* NUMERICAL_METHODS */