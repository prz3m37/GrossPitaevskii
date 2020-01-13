#include "GrossPitaevski.h"
#include <complex>

std::complex<double> GrossPitaevskiiEquations::getLaplaceOperatior(std::complex<double> (*Psi)(double, double, double), double x, double y, double t)
{
    double xStep;
    double yStep; 
    std::complex<double> laplaceOperator;
    laplaceOperator = ( Psi(x - xStep, y, t) - 2.0 * Psi(x, y, t) + Psi(x + xStep, y, t)) / (pow(xStep, 2) ) + 
                      ( Psi(x, y - yStep, t) - 2.0 * Psi(x, y, t) + Psi(x, y + yStep, t)) / (pow(xStep, 2) );

    return laplaceOperator;
};

std::complex<double> GrossPitaevskiiEquations::getGaussPulse(double x, double y, double t)
{
    double kx;
    double ky;
    double deltaW;
    double wx;

    const std::complex<double> i(0.0,1.0);
    double gaussPulse = exp(-1 * ((pow(x, 2) + pow(y, 2)) / (2 * pow(wx, 2)) )); 
    std::complex<double> planeWave = exp((kx * x + ky * y - deltaW * t) * i);  
    std::complex<double> finalPulse = gaussPulse * planeWave;

    return finalPulse;
};


std::complex<double> GrossPitaevskiiEquations::getNonSpinFirstGPEquation(double x, double y, double t)
{
    double planckConst; 
    double rabiFrequency;
    double excitonDecayRate;
    double photonDecayRate;

    const std::complex<double> i(0.0,1.0);
    //getGaussPulse(x, y, t) + rabiFrequency * 1 + ( (-i * planckConst * photonDecayRate) / 2.0 - pow(planckConst, 2) * getLaplaceOperatior(x))
    return 0;
};


std::complex<double> GrossPitaevskiiEquations::getNonSpinSecondGPEquation(double x, double y, double t)
{

};
