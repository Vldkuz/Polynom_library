#pragma once
#include <fstream>
#include "Dinamic_Structure.h"

struct Polynom{
	Dinamic_Structure factors;
	unsigned int degree;
};

Polynom InStreamPolynom(std::ifstream FileStream);

void OutStreamPolynom(std::ofstream FileStream,Polynom d1);

Polynom GetFactorsDerivative(Polynom& d1);

int GetValuePolynomPoint(Polynom& d1, int point);

int GetDerivativePolynomPoint(Polynom& d1, int point);

Polynom SummPolynom(Polynom &d1, Polynom &d2);

Polynom DifferencePolynom(Polynom &d1, Polynom &d2);

Polynom MultipliedPolynom(Polynom &d1, Polynom &d2);

Polynom DividedPolynom(Polynom& d1, Polynom &d2 );



