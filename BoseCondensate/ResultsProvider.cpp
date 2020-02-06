#include "ResultsProvider.h"
#include <complex.h>

void ResultsProvider::computeResults()
{
    int xsize;
    int ysize;
    double t = 0;
    double dt;
    int numOfTimeSteps;
    std::complex<double> PsiC[xsize * ysize];
    std::complex<double> PsiX[xsize * ysize];
    
    std::string message = "[INFO] Runge Kutta calculations has started";
    utils.saveLog(message);

    for (int n = 0; n < numOfTimeSteps; n++)
    {
        grossPitvk.getRungeKutta(PsiC, PsiX, t, dt);
        t += dt;
    }
    std::string message = "[INFO] Runge Kutta calculations has finished";
    utils.saveLog(message);
}