#include "Utils.h"
#include <fstream>
#include <sys/stat.h>
#include <chrono>

bool Utils::checkLogFileExistence (const std::string& name)
{
struct stat buffer;   
return (stat (name.c_str(), &buffer) == 0); 
};

void Utils::deleteLogFile()
{
    if( std::remove("logFile.txt") == 0 )
    {
        printf( "[INFO] Log file deleted\n" );
    }
    else 
    {
        printf( "[INFO] Log file deleted, system message:  %s\n", strerror( errno ) );
    }
};

std::string Utils::getTime()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
    std::string time(buffer);
    return time;
};

void Utils::saveLog(std::string message)
{
    std::string currentTime = getTime();
	std::ofstream logFile;

	logFile.open("logFile.txt", std::ios_base::app);
	logFile << currentTime + " " + message << "\n";
	logFile.close();
};

// simple for now maybe in future will change the saving loop
void Utils::saveResultsToFile(std::complex<double> Psi[], std::ofstream &of)
{
    int xsize;
    int ysize;
    int printXStep;
    int printYStep;

    for (int x= 0; x < xsize; x+= printXStep)
    {
        for (int y = 0; y < ysize; y += printYStep)
        {
            if (y > 0)
                of << '\t';
            of << std::setprecision(5) << Psi[x * ysize + y];
        }
        of << std::endl;
    }
}

std::complex<double> Utils::csquare(std::complex<double> z)
{
    return z * z; 
};

double Utils::rsquare(double x)
{
    return x * x; 
};