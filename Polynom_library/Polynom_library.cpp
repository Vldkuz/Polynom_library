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
    d1 = d3.q;
    d2 = d3.r;
    std::ofstream Out("Test1.txt");
    OutStreamPolynom(Out, d1);
    OutStreamPolynom(Out, d2);

    return 0;
}

