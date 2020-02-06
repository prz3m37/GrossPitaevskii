#ifndef RESULTS_PROVIDER
#define RESULTS_PROVIDER
#include <complex.h> 
#include "GrossPitaevski.cpp"
#include "Utils.cpp"

class ResultsProvider {
    private:
        Utils utils;
        GrossPitaevski grossPitvk;
    public:    
        void computeResults();
};

#endif /* RESULTS_PROVIDER */