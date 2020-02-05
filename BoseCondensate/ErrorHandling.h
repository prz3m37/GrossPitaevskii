#ifndef ERROR_HANDLING
#define ERROR_HANDLING
#include <string>
#include "Utils.cpp"

class ErrorHandling{
    private:
        Utils utils;
    public:
        bool checkRungeKuttaStability(const double meshConstX, const double meshConstY, const double mc,
        const double hbar, const double dt);
};
#endif /* ERROR_HANDLING */