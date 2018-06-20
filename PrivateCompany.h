# Company-improved

#pragma once
#include "Company.h"

#include<iostream>
class PrivateCompany :
	public Company
{
public:
	PrivateCompany(const char* name = "NO NAME", int tP = 0, int sP = 0, int sR = 0);

	bool perform(std::string task);
	double reliabilityRate() const;
	void print() const { std::cout << "Private company : " << successRate << " " << getName(); }

	friend std::ostream& operator<<(std::ostream& os, const PrivateCompany& pC);
	friend std::istream& operator>>(std::istream& in, PrivateCompany& pC);

private:
	int successRate;
};

