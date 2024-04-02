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

    Beer b1("Stella Artois", 750);
    //std::clog << b1.IsGood() << endl;
    Beer b2("Heineken", 330);
    //std::clog << "b2: "<< b2.IsGood() << endl;

    b1.AddFrom(b2, 200);

    b1.Print();
    b2.Print();

    std::cout << b1.HasMix(b2.GetName()) << endl;
    std::cout << b2.HasMix("Corona") << endl;

    std::clog.rdbuf(old_buf);
    fLog.close();

    return 0;
}