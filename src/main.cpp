#include "Config.hpp"
#include "gomea.hpp"
#include "gomeaIMS.hpp"
#include "gomeaP3_MI.hpp"


int main(int argc, char **argv)
{
    Config *config = new Config();
    config->parseCommandLine(argc, argv);
    config->parseEnv();
    config->checkOptions();
    //config->printOverview(); // toggle on if you want annoying output that fills entire terminal everytime :)

    config->rng.seed(config->randomSeed);

    GOMEA *gomeaInstance;
    if (config->populationScheme == 0 || config->populationScheme == 1)
        gomeaInstance = new gomeaIMS(config);
    else
        gomeaInstance = new gomeaP3_MI(config);
    
    try
    {
        gomeaInstance->run();
    }
    catch (customException &ex)
    {}

    delete gomeaInstance;
    delete config;
    
    return 0;
}
