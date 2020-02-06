#include "ConfigurationParser.cpp"
using namespace std ;

void f()
{
    int numOfTimeSteps = 10;
    double t=0;
    double dt = 0.01;
    for (int n = 0; n < numOfTimeSteps; n++)
    {
        //cout<<t<<endl;
        t += 1;
        cout<<t<<endl;
    }

};

int main()
{

    // ConfigParser cfgParser;
    // const std::string cfgFile = "params.txt";

    // const std::string polaritionsMass = "polaritionsMass";
    // const std::string fieldAmplitude = "fieldAmplitude";
    // const std::string planckConst = "planckConst";
    // const std::string meshConstX = "meshConstX";
    // const std::string meshConstY = "meshConstX";
    // const std::string bosonMass = "bosonMass";
    // const std::string meshSizeX = "meshSizeX";
    // const std::string meshSizeY = "meshSizeY";
    // const std::string timeStep = "timeStep";
    // const std::string freqkx = "freqkx";
    // const std::string freqky = "freqky";

    // std::map<std::string,std::string> parameters;
    // parameters = cfgParser.readParams(cfgFile);

    // double mp = cfgParser.getReqiuredParam<double>(polaritionsMass, parameters);
    // double mConstX = cfgParser.getReqiuredParam<double>(meshConstX, parameters);
    // double mConstY = cfgParser.getReqiuredParam<double>(meshConstY, parameters);
    // double f = cfgParser.getReqiuredParam<double>(fieldAmplitude, parameters);
    // double hbar = cfgParser.getReqiuredParam<double>(planckConst, parameters);
    // double mc = cfgParser.getReqiuredParam<double>(bosonMass, parameters);
    // double dt = cfgParser.getReqiuredParam<double>(timeStep, parameters);
    // double wkx = cfgParser.getReqiuredParam<double>(freqkx, parameters);
    // double wky = cfgParser.getReqiuredParam<double>(freqky, parameters);

    // int mSizeX = cfgParser.getReqiuredParam<int>(meshSizeX, parameters);
    // int mSizeY = cfgParser.getReqiuredParam<int>(meshSizeY, parameters);

    f();

};
