#include <iostream>
#include <fstream>
#include "Beer.h"

using std::endl;

int main ()
{
    try
    {
        
        Beer b1("Corona", 330), b2("Heineken", 330);
        b1.AddFrom(b2, 300);

        b1.Print();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
        exit(-1);
    }
    
    return 0;
}