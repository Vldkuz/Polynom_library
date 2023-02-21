#include "Polynom_Functions.h"
#include <string>

unsigned int GetFactorsCount(std::string temp) {
	unsigned int count = 0;
	unsigned int size_temp = temp.length();

	for (int i = 0; i < size_temp; ++i) {
		if (temp[i] == ' ')
			++count;
	}

	++count;
	return count;
}


Polynom InStreamPolynom(std::ifstream &FileStream)//Коэффициент при наибольшей степени первый
{
	Polynom d1;
	std::string str;
	getline(FileStream, str);
	unsigned int size_str = str.length();
	unsigned int factors_c = GetFactorsCount(str);
	unsigned int k = 0;
	//1 23 32 count_prob = n-1 // n = count_prob + 1
	// Доказывается по индукции

	int* factors = new int[factors_c];
	int d = 0;
	while (d < size_str) {
		std::string temp;
		while (str[d] != ' ' && d < size_str) {
			temp += str[d];
			++d;
		}

		factors[k++] = stoi(temp);
		++d;
	}

	d1.factors = factors;
	d1.degree = factors_c - 1;
	return d1;
}

void OutStreamPolynom(std::ofstream &FileStream,Polynom &d1)//Коэффициент при наибольшей степени первый
{
	FileStream << d1.degree << std::endl;
	for (int i = 0; i < d1.degree + 1; ++i) {
		FileStream << d1.factors[i] << " ";
	}
	FileStream << std::endl;
}

Polynom GetFactorsDerivative(Polynom& d1)
{
	Polynom d2;
	d2.degree = d1.degree - 1;
	d2.factors = new int[d1.degree];

	unsigned int k = 0;
	for (int i = 0; i < d1.degree + 1; ++i) {
		int d = (d1.degree - i) * d1.factors[i];
		d2.factors[k++] = d;
	}

	return d2;
}

int GetValuePolynomPoint(Polynom& d1, int point)
{
	int summ = 0;
	for (int i = 0; i < d1.degree + 1; ++i) {
		summ += pow(point, d1.degree - i) * d1.factors[i];
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
	unsigned int k = 0;
	d3.degree = std::max(d1.degree, d2.degree);
	d3.factors = new int[d3.degree + 1];

	for (int i = 0; i < d3.degree + 1; ++i) {
		if (d2.degree - i >= 0 && d1.degree - i >= 0) {
			int temp = d2.factors[i] + d1.factors[i];
			d3.factors[k++] = temp;
		}

		if (d2.degree - i < 0 && d1.degree - i >= 0) {
			int temp = d1.factors[i];
			d3.factors[k++] = temp;
		}

		if (d1.degree - i < 0 && d2.degree - i >= 0) {
			int temp = d2.factors[i];
			d3.factors[k++] = temp;
		}
	}


	return d3;
}

Polynom DifferencePolynom(Polynom& d1, Polynom& d2)
{
	Polynom d3;
	unsigned int k = 0;
	d3.degree = std::max(d1.degree, d2.degree);
	d3.factors = new int[d3.degree + 1];
	for (int i = 0; i < d3.degree + 1; ++i) {
		if (d2.degree - i >= 0 && d1.degree - i >= 0) {
			int temp = d1.factors[i] - d2.factors[i];
			d3.factors[k++] = temp;
		}

		if (d2.degree - i < 0 && d1.degree - i >= 0) {
			int temp = d1.factors[i];
			d3.factors[k++] = temp;
		}

		if (d1.degree - i < 0 && d2.degree - i >= 0) {
			int temp = -d2.factors[i];
			d3.factors[k++] = temp;
		}
	}

	return d3;
}

Polynom MultipliedPolynom(Polynom& d1, Polynom& d2)
{
	Polynom d3;
	d3.degree = d1.degree + d2.degree;
	d3.factors = new int[d3.degree + 1];



	for (int i = 0; i < d1.degree + 1; ++i) {
		for (int j = 0; j < d2.degree + 1; ++j) {
			d3.factors[i + j] += d1.factors[i] * d2.factors[j];
		}
	}

	return d3;
}

Polynom DividedPolynom(Polynom& d1, Polynom& d2)
{
	return Polynom();
}
