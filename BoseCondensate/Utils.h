#ifndef UTILS
#define UTILS
#include <string>
#include <complex.h>

class Utils{
    public:
        void deleteLogFile();
        std::string getTime();
        void saveLog(std::string message);
        void saveResultsToFile(std::complex<double>Psi[]);
        bool checkLogFileExistence (const std::string& name); 
};

#endif /* UTILS */