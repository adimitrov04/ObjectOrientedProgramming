#include <iostream>
#include <fstream>
#include "Beer.h"

using std::endl;

int main ()
{
    // Redirect clog
    std::ofstream fLog("db.log", std::ios::app);
    auto old_buf = std::clog.rdbuf();
    std::clog.rdbuf(fLog.rdbuf());

    std::ifstream input("in.txt");
    Beer b1, b2;
    b1.Read(input);
    b2.Read(input);
    input.close();
    
    b1.Print();
    b2.Print();

    b2.AddFrom(b1, b1.GetVolume() / 2);
    b1.Print();
    b2.Print();

    std::clog.rdbuf(old_buf);
    fLog.close();

    return 0;
}