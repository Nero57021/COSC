#include "CalculatorMaths.h"
#include <cmath>

using namespace std;
//Jeremy Bayangos
//Sample Project
//With helped from people at stack overflow

CalculatorMaths::CalculatorMaths()
{
}

CalculatorMaths::CalculatorMaths(bool radians)
{
	// Is this enough? multiply all angle things with angleToUse?
	angleToUse = radians ? degreeToRadian : radianToDegrees;
}


CalculatorMaths::~CalculatorMaths()
{
}

double CalculatorMaths::Add(double lhs, double rhs)
{
	return lhs + rhs;
}

double CalculatorMaths::Subtract(double lhs, double rhs)
{
	return lhs - rhs;
}

double CalculatorMaths::Divide(double lhs, double rhs)
{
	return lhs / rhs;
}

double CalculatorMaths::Multiply(double lhs, double rhs)
{
	return lhs * rhs;
}

// must convert to int first
int CalculatorMaths::Modulous(int lhs, int rhs)
{
	return lhs % rhs;
}

double CalculatorMaths::SquareRoot(double x)
{
	return sqrt(x);
}

// e ^ x
double CalculatorMaths::Exponential(double x)
{
	return exp(x); // raise e (exponent) to the power of x
}

// Log10
double CalculatorMaths::CommonLog(double x)
{
	return log10(x);
}

// LogE
double CalculatorMaths::NaturalLog(double x)
{
	return log(x); // log e
}

// Must convert to int first
int CalculatorMaths::Factorial(int x)
{
	if (x > 1)
		return x * Factorial(x - 1);
	else
		return 1;
}

double CalculatorMaths::RaiseToPower(double x, double byY)
{
	// Shall we do some cool bit shifting thing?
	return pow(x, byY);
}

double CalculatorMaths::Percent(double xPercent, double ofY)
{

	return (ofY / 100) * xPercent;
}

double CalculatorMaths::Pi()
{
	return pi;
}

double CalculatorMaths::E()
{
	return e;
}

double CalculatorMaths::Sin(double x)
{
	x = x * (3.14159 / 180);
	int y = round(sin(x));
	return y;
}

double CalculatorMaths::Cos(double x)
{
	x = x * (3.14159 / 180);
	int y = round(cos(x));
	return y;
}

double CalculatorMaths::Tan(double x)
{
	x = x * (3.14159 / 180);
	int y = round(tan(x));
	return y;
}

double CalculatorMaths::ASin(double x)
{
	return asin(x);
}

double CalculatorMaths::ACos(double x)
{
	return acos(x);
}

double CalculatorMaths::ATan(double x)
{
	return atan(x);
}

double CalculatorMaths::Atan2(double x, double y)
{
	return atan2(x, y);
}
