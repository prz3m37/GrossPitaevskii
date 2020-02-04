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

void Utils::saveResultsToFile(std::complex<double>Psi[])
{
    int arraySize = sizeof(Psi) / sizeof(std::complex<double>);
    std::ofstream resultFile;

    if (resultFile.is_open())
    {
        resultFile.open("resultFile.txt", std::ios_base::app);
        for(int i = 0; i < arraySize; i ++)
        {
            resultFile << Psi[i] << "\n";
        }
        std::string message = "[INFO] Results saved to file.";
        saveLog(message);
        resultFile.close();
    }
    else
    {
        std::string message = "[ERROR] Unable to open file.";
        saveLog(message);
    }
}