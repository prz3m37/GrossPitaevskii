#include "ConfigurationParser.cpp"
using namespace std ;


template <typename T>
void foo() {
  cout << sizeof(T)<<endl;
}

int main()
{
    ConfigParser cfgParser;

    std::string  parameter;
    const std::string cfgFile = "params.txt";
    const std::string requiredParameter = "wkx" ;
    //getReqiuredParam<double>(requiredParameter, cfgFile);
    //int par;
    //par = stoi(parameter.c_str());
    double var;
    std::map<std::string,std::string> parameters;
    parameters = cfgParser.readParams(cfgFile);
    var = cfgParser.getReqiuredParam<double>(requiredParameter, parameters);
    cout<<var<<endl;
    
    return 0;
}
