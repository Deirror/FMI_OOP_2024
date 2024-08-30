#include <iostream>

struct ComplexNumber
{
	double realPart = 0.;
	double imgPart = 0.;


	void print()
	{
		std::cout << realPart << " + " << imgPart << "i\n";
	}
};

ComplexNumber sum(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	ComplexNumber result;

	result.realPart = lhs.realPart + rhs.realPart;
	result.imgPart = lhs.imgPart + rhs.imgPart;

	return result;
}

ComplexNumber multiply(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	ComplexNumber result;

	result.realPart = lhs.realPart*rhs.realPart - lhs.imgPart*rhs.imgPart;
	result.imgPart = lhs.realPart*rhs.imgPart + lhs.imgPart*rhs.realPart;

	return result;
}

int main()
{
	ComplexNumber cn1;
	cn1.realPart = 2;
	cn1.imgPart = 2;

	ComplexNumber cn2;
	cn2.realPart = 1;
	cn2.imgPart = 1;

	ComplexNumber cn3 = sum(cn1, cn2);

	cn3.print();

	cn3 = multiply(cn1, cn2);

	cn3.print();

	return 0;
}