#include "ErrorHandling.h"
#include <complex.h>

bool ErrorHandling::checkRungeKuttaStability(const double meshConstX, const double meshConstY, const double mc, 
    const double hbar, const double dt)
{
    double CFLCondition = (hbar * dt / (pow(meshConstX, 2) * mc)) + (hbar * dt / (pow(meshConstY, 2) * mc));
    if (CFLCondition <= 1)
    {
        std:: string message = "[INFO] CFL condondition fulfilled.";
        utils.saveLog(message);
        return true;
    }
    else
    {
        std:: string message = "[INFO] CFL condondition not fulfilled.";
        utils.saveLog(message);
        return false;
    }
};

