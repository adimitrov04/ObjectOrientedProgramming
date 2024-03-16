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

    Beer b1("Stella &rtois", 750);
    //std::clog << b1.IsGood() << endl;
    Beer b2("Corona", 175);
    std::clog << "b2: "<< b2.IsGood() << endl;

    b1.AddFrom(b2, 200);

    b1.Print();
    b2.Print();

    std::clog.rdbuf(old_buf);
    fLog.close();

    return 0;
}