# Company-improved

#pragma once
#include "Company.h"

class StateOwnedCompany :
	public Company
{
public:
	StateOwnedCompany(const char* name = "NO NAME", int tP = 0, int sP = 0);
	
	bool perform(std::string task);
	double reliabilityRate() const;

	void print() const { std::cout << "State owned company : " << getName(); }

	friend std::ostream& operator<<(std::ostream& os, const StateOwnedCompany& sOC);
	friend std::istream& operator>>(std::istream& in, StateOwnedCompany& sOC);

};

