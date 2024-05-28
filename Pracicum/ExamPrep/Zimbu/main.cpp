#include <iostream>
#include <fstream>
#include <stdexcept>

#include <string>

#include "Component.h"
#include "Configuration.h"

int main ()
{
    try
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
        delete config;
    }
    catch (const std::bad_alloc&)
    // Only catch bad alloc because no other exception can be thrown by main as it currently is
    {
        std::cerr << "bad alloc... terminating.\n";
        return -1;
    }
    
    return 0;
}