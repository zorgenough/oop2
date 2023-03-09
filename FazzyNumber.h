#pragma once
#include <iostream>
#include <string>

class FazzyNumber
{
private:
	double* e1;
	double* e2;
	double* x;
public:
	FazzyNumber();
	FazzyNumber(double, double, double);
	FazzyNumber(const FazzyNumber& object);
	~FazzyNumber();

	std::string toString();

	void Set_e1(double);
	void Set_e2(double);
	void Set_x(double);

	double Get_e1();
	double Get_e2();
	double Get_x();

	FazzyNumber operator + (FazzyNumber);
	FazzyNumber operator - (FazzyNumber);
	FazzyNumber operator * (FazzyNumber);
	FazzyNumber operator / (FazzyNumber);

	bool operator == (FazzyNumber);

	friend std::ostream& operator << (std::ostream&, FazzyNumber&);
	friend std::istream& operator >> (std::istream&, FazzyNumber&);

	FazzyNumber& operator = (const FazzyNumber& object);
};

