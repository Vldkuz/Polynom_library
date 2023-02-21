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

    std::ofstream Out("Test.txt");
    OutStreamPolynom(Out, d1);
    OutStreamPolynom(Out, d2);
    

    return 0;
}

