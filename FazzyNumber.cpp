#include "FazzyNumber.h"

FazzyNumber::FazzyNumber()
{
	e1 = new double;
	e2 = new double;
	x = new double;
	*e1 = 0;
	*e2 = 0;
	*x = 0;
}

FazzyNumber::FazzyNumber(double _e1, double _x, double _e2)
{
	e1 = new double;
	e2 = new double;
	x = new double;
	*e1 = _e1;
	*e2 = _e2;
	*x = _x;
}

FazzyNumber::FazzyNumber(const FazzyNumber& object)
{
	this->e1 = new double;
	this->e2 = new double;
	this->x = new double;
	*this->e1 = *object.e1 ;
	*this->e2 = *object.e2 ;
	*this->x = *object.x ;
}

FazzyNumber::~FazzyNumber()
{
	delete e1;
	delete e2;
	delete x;
}

std::string FazzyNumber::toString()
{
	std::string str = "(" + std::to_string(*x - *e1) + ", " + std::to_string(*x) + ", " + std::to_string(*x + *e2) + ")";
	return str;
}

void FazzyNumber::Set_e1(double _e1)
{
	*e1 = _e1;
}

void FazzyNumber::Set_e2(double _e2)
{
	*e1 = _e2;
}

void FazzyNumber::Set_x(double _x)
{
	*e1 = _x;
}

double FazzyNumber::Get_e1()
{
	return *e1;
}

double FazzyNumber::Get_e2()
{
	return *e2;
}

double FazzyNumber::Get_x()
{
	return *x;
}

FazzyNumber FazzyNumber::operator+(FazzyNumber object)
{
	FazzyNumber temp;
	*temp.e1 = *e1 + *object.e1;
	*temp.x = *x + *object.x;
	*temp.e2 = *e2 + *object.e2;
	return temp;
}

FazzyNumber FazzyNumber::operator-(FazzyNumber object)
{
	FazzyNumber temp;
	*temp.e1 = *e1 + *object.e1;
	*temp.x = *x - *object.x;
	*temp.e2 = *e2 + *object.e2;
	return temp;
}

FazzyNumber FazzyNumber::operator*(FazzyNumber object)
{
	FazzyNumber temp;
	*temp.e1 = *object.x * *e1 + *x * *object.e1 - *e1 * *object.e1;
	*temp.x = *x * *object.x;
	*temp.e2 = *object.x * *e2 + *x * *object.e2 + *e2 * *object.e2;
	return temp;
}

FazzyNumber FazzyNumber::operator/(FazzyNumber object)
{
	FazzyNumber temp;
	*temp.e1 = (*x * *object.e2 + *object.x * *e1) / (*object.x * *object.x + *object.x * *object.e2);
	*temp.x = *x / *object.x;
	*temp.e2 = (*object.x * *e2 + *x * *object.e1) / (*object.x * *object.x - *object.x * *object.e1);
	return temp;
}

bool FazzyNumber::operator==(FazzyNumber object)
{
	return (*e1 == *object.e1) && (*e2 == *object.e2) && (*x == *object.x);
}

FazzyNumber& FazzyNumber::operator=(const FazzyNumber& object)
{
	if (this == &object)
	{
		return *this;
	}

	*e1 = *object.e1;
	*e2 = *object.e2;
	*x = *object.x;

	return *this;
}

std::ostream& operator<<(std::ostream& stream, FazzyNumber& object)
{
	stream << object.toString();
	return stream;
}

std::istream& operator>>(std::istream& stream, FazzyNumber& object)
{
	stream >> *object.e1;
	stream >> *object.x;
	stream >> *object.e2;
	return stream;
}
