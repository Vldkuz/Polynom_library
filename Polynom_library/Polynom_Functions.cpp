#include "Polynom_Functions.h"
#include <string>

Polynom InStreamPolynom(std::ifstream FileStream)//Коэффициент при наибольшей степени первый
{
	Polynom d1;
	std::string sym = "1";
	unsigned int count = 0;
	while (sym != "\n") {
		FileStream >> sym;
		int elem = stoi(sym);
		d1.factors.push_back(elem);
		++count;
	}

	d1.degree = count - 1;
	return d1;
}

void OutStreamPolynom(std::ofstream FileStream,Polynom d1)//Коэффициент при наибольшей степени первый
{
	FileStream << d1.degree << std::endl;
	for (int i = 0; i < d1.factors.get_size(); ++i) {
		FileStream << d1.factors.get_elem(i) << " ";
	}
}

Polynom GetFactorsDerivative(Polynom& d1)
{
	Polynom d2;
	d2.degree = d1.degree - 1;
	for (int i = 0; i < d1.degree + 1; ++i) {
		int d = (d1.degree - i) * d1.factors.get_elem(i);
		d2.factors.push_back(d);
	}

	return d2;
}

int GetValuePolynomPoint(Polynom& d1, int point)
{
	int summ = 0;
	for (int i = 0; i < d1.degree + 1; ++i) {
		summ += pow(point, d1.degree - i) * d1.factors.get_elem(i);
	}

	return summ;
}

int GetDerivativePolynomPoint(Polynom& d1, int point)
{
	Polynom d2 = GetFactorsDerivative(d1);
	return GetValuePolynomPoint(d2, point);
}

Polynom SummPolynom(Polynom& d1, Polynom& d2)
{
	Polynom d3;
	d3.degree = std::max(d1.degree, d2.degree);
	for (int i = 0; i < d3.degree + 1; ++i) {
		if (d2.degree - i >= 0 && d1.degree - i >= 0) {
			int temp = d2.factors.get_elem(i) + d1.factors.get_elem(i);
			d3.factors.push_back(temp);
		}

		if (d2.degree - i < 0 && d1.degree - i >= 0) {
			int temp = d1.factors.get_elem(i);
			d3.factors.push_back(temp);
		}

		if (d1.degree - i < 0 && d2.degree - i >= 0) {
			int temp = d2.factors.get_elem(i);
			d3.factors.push_back(temp);
		}
	}


	return d3;
}

Polynom DifferencePolynom(Polynom& d1, Polynom& d2)
{
	Polynom d3;
	d3.degree = std::max(d1.degree, d2.degree);
	for (int i = 0; i < d3.degree + 1; ++i) {
		if (d2.degree - i >= 0 && d1.degree - i >= 0) {
			int temp = d1.factors.get_elem(i) - d2.factors.get_elem(i);
			d3.factors.push_back(temp);
		}

		if (d2.degree - i < 0 && d1.degree - i >= 0) {
			int temp = d1.factors.get_elem(i);
			d3.factors.push_back(temp);
		}

		if (d1.degree - i < 0 && d2.degree - i >= 0) {
			int temp = -d2.factors.get_elem(i);
			d3.factors.push_back(temp);
		}
	}


	return d3;
}

Polynom MultipliedPolynom(Polynom& d1, Polynom& d2)
{
	


}

Polynom DividedPolynom(Polynom& d1, Polynom& d2)
{
	return Polynom();
}
