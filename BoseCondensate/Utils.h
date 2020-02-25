#ifndef UTILS
#define UTILS
#include <string>
#include <complex.h>

class Utils{
    public:
        void deleteLogFile();
        std::string getTime();
        double rsquare(double x);
        void saveLog(std::string message);
        std::complex<double> csquare(std::complex<double> z);
        bool checkLogFileExistence (const std::string& name);
        void saveResultsToFile(std::complex<double> Psi[], std::ofstream &of);
};

#endif /* UTILS */