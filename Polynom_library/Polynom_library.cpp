#include <iostream>
#include <fstream>
#include "Polynom_Functions.h"


int main()
{
    Polynom d1;
    Polynom d2;

    std::ifstream Test("Test.txt");
    d1 = InStreamPolynom(Test);
    d2 = InStreamPolynom(Test);

    DividedPolynom d3 = DividePolynom(d1, d2);
    std::ofstream Test1("Test1.txt");
    OutStreamPolynom(Test1, d3.q);
    OutStreamPolynom(Test1, d3.r);

    return 0;
}

