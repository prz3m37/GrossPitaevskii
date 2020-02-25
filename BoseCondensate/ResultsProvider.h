#ifndef RESULTS_PROVIDER
#define RESULTS_PROVIDER
#include <complex.h> 
#include "GrossPitaevski.cpp"
#include "ErrorHandler.cpp"
#include "Utils.cpp"

class ResultsProvider {
    private:
        Utils utils;
        ErrorHandler errHandler;
        GrossPitaevski grossPitvk;
    public:    
        void computeResults();
};

#endif /* RESULTS_PROVIDER */