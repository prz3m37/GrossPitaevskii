#ifndef GROSS_PITAEVSKII
#define GROSS_PITAEVSKII
#include <complex>

class GrossPitaevskiiEquations{
    private:
        std::complex<double> getGaussPulse(double x, double y, double t);
        std::complex<double> getLaplaceOperatior(std::complex<double> (*Psi)(double, double, double),
         double x, double y, double t);

    public:
        std::complex<double> getNonSpinFirstGPEquation(double x, double y, double t);
        std::complex<double> getNonSpinSecondGPEquation(double x, double y, double t);

        std::complex<double> getSpinFirstGPEquation(double x, double y, double t);
        std::complex<double> getSpinSecondGPEquation(double x, double y, double t);
        std::complex<double> getSpinThirdGPEquation(double x, double y, double t);
        std::complex<double> getSpinFourthGPEquation(double x, double y, double t);

};

#endif /* GROSS_PITAEVSKII */