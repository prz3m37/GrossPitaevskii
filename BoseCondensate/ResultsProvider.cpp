#include "ResultsProvider.h"
#include <complex.h>

void ResultsProvider::computeResults()
{
    int xsize;
    int ysize;
    double t = 0;
    double dt;
    int numOfTimeSteps;
    std::ofstream resultFile("resultFile.dat");
    std::complex<double> PsiC[xsize * ysize];
    std::complex<double> PsiX[xsize * ysize];

    if (errHandler.checkRungeKuttaStability())
    {
        std::string messageCFL = "[INFO] CFL condition fulfilled";
        std::string messageRK = "[INFO] Runge Kutta calculations has started";
        utils.saveLog(messageCFL);
        utils.saveLog(messageRK);
        for (int n = 0; n < numOfTimeSteps; n++)
        {
            grossPitvk.getRungeKutta(PsiC, PsiX, t, dt);
            grossPitvk.applySafeWindow(PsiC, PsiX);
            utils.saveResultsToFile(PsiC, resultFile);
            utils.saveResultsToFile(PsiX, resultFile);
            t += dt;
        }
        std::string message = "[INFO] Runge Kutta calculations has finished";
        utils.saveLog(message);
    }   
    else
    {
        std::string messageCFLerr = "[NUMMERICAL ERROR] CFL condition not-fulfilled";
        utils.saveLog(messageCFLerr);
    }
    resultFile.close();
}