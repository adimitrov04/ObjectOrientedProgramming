#include <iostream>
#include <fstream>
#include <stdexcept>

#include <string>

#include "Component.h"
#include "Configuration.h"

int main ()
{
    Configuration* config = Configuration::create_configuration();
    if (config == nullptr)
        return -1;

    std::cout << config << std::endl;

    std::string outputFileName;
    
    std::cout << "Enter file name to save config info in: ";
    std::cin >> outputFileName;

    std::ofstream outFile(outputFileName);
    outFile << config;
    outFile.close();
    
    return 0;
}