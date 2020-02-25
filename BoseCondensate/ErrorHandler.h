#ifndef ERROR_HANDLER
#define ERROR_HANDLER
#include <string>
#include "Utils.cpp"

class ErrorHandler{
    private:
        Utils utils;
    public:
        bool checkRungeKuttaStability();
};
#endif /* ERROR_HANDLER */