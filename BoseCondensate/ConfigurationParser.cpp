#include "Utils.cpp"
#include <iostream>
#include <fstream>
#include <map>

class ConfigParser{
    public:
        Utils utils;
        template <typename T>
        const T getReqiuredParam(std::string requiredParameter, std::map<std::string, std::string> parameters)
        {
            std::string chosenParameter;
            chosenParameter = parameters[requiredParameter];

            if(sizeof(T) == 4)
            {
                int convertedParam;
                convertedParam = std::stoi(chosenParameter.c_str());
                std:: string message = "[INFO] Parameter: ==> " + requiredParameter + " sucesfully loaded.";
                utils.saveLog(message);
                return convertedParam;
            }
            if(sizeof(T) == 8)
            {
                double convertedParam;
                convertedParam = std::stod(chosenParameter.c_str());
                std::string message = "[INFO] Parameter: ==> " + requiredParameter + " sucesfully loaded.";
                utils.saveLog(message);
                return convertedParam;
            }
            else
            {
                std:: string message = "[ERROR] Parameter: ==>  "+ requiredParameter + " unsucesfully loaded.";
                utils.saveLog(message);
                return 0;
            }
        }; 

        std::map<std::string,std::string> readParams(const std::string congigFile)
        {   
            std::map<std::string,std::string> params;
            std::ifstream cFile (congigFile);
            if (cFile.is_open())
            {
                std::string line;
                while(getline(cFile, line)){
                    line.erase(std::remove_if(line.begin(), line.end(), std::isspace),
                                        line.end());
                    if(line[0] == '#' || line.empty())
                        continue;
                    char delimiterPos = line.find("=");
                    std::string name = line.substr(0, delimiterPos);
                    std::string value = line.substr(delimiterPos + 1);
                    params.insert(std::pair<std::string,std::string>(name,value));
                }
            
            std::string message = "[INFO] All values were sucesfully readed from params file.";
            utils.saveLog(message);
            }
            else {
                std::string message = "[ERROR] Couldn't open config file.";
                utils.saveLog(message);
            }
        return params;
        };
};
