#include <iostream>
#include <fstream>
#include <map>

class ConfigParser{
    public:
        template <typename T>
        const T getReqiuredParam(std::string requiredParameter, std::map<std::string,std::string> parameters){

            std::string chosenParameter;
            chosenParameter = parameters[requiredParameter];

            if(sizeof(T) == 4){
                int convertedParam;
                convertedParam = std::stoi(chosenParameter.c_str());
                return convertedParam;
            }

            if(sizeof(T) == 8){
                double convertedParam;
                convertedParam = std::stod(chosenParameter.c_str());
                return convertedParam;
            }

            else{
                return 0;
            }
        }; 

        std::map<std::string,std::string> readParams(const std::string congigFile){   
            std::map<std::string,std::string> params;
            std::ifstream cFile (congigFile);
            if (cFile.is_open())
            {
                std::string line;
                while(getline(cFile, line)){
                    line.erase(std::remove_if(line.begin(), line.end(), isspace),
                                        line.end());
                    if(line[0] == '#' || line.empty())
                        continue;
                    char delimiterPos = line.find("=");
                    std::string name = line.substr(0, delimiterPos);
                    std::string value = line.substr(delimiterPos + 1);
                    params.insert(std::pair<std::string,std::string>(name,value));
                }
            
            printf("[INFO] All values were loaded. \n");
                
            }
            else {
                std::cout << "[ERROR] Couldn't open config file.\n";
            }
        return params;
        };
};
