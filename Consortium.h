# Company-improved

#pragma once
#include "Company.h"
#include "PrivateCompany.h"
#include "StateOwnedCompany.h"
#include<vector>

class Consortium :
	public Company
{
public:
	Consortium(const char* name = "NO NAME", int tP = 0, int sP = 0, int nOS = 0,
		std::vector<Company*> subcontractors = std::vector<Company*> ());
	//~Consortium() { Destroy(); }
	Consortium(const Consortium& c) { CopyFrom(c); }
	Consortium& operator=(const Consortium& c);
	//void expand();
	bool perform(std::string task);
	double reliabilityRate() const;

	void AddSubcontractor(const StateOwnedCompany& sOC);
	void AddSubcontractor(const PrivateCompany& pC);
	void AddSubcontractor(const Consortium& c);
	void deleteSubcontractor(const char* name);
	void printStatus() const;
	void print() const { std::cout << "Consortium : " << numOfSubcontractors << " " << getName(); }

	friend std::ostream& operator<<(std::ostream& os, const Consortium& c);
	friend std::istream& operator>>(std::istream& in, Consortium& c);

private:
	//void Destroy();
	void CopyFrom(const Consortium& c);
	std::vector<Company*> subcontractors;
	//Company ** subcontractors;
	//int maxSubscontractors = 10;
	int numOfSubcontractors;
};
