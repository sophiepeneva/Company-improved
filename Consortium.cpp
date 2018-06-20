# Company-improved

#include "Consortium.h"

void Consortium::CopyFrom(const Consortium& c)
{
	setName(c.getName());
	setTakenProjects(c.getTakenProjects());
	setSuccessfulProjects(c.getSuccessfulProjects());
	subcontractors = c.subcontractors;
}


Consortium::Consortium(const char* name, int tP, int sP, int nOS, std::vector<Company*> subcontractors)
	: Company(name, tP, sP), numOfSubcontractors(nOS)
{
	this->subcontractors = subcontractors;
}

Consortium& Consortium::operator=(const Consortium& c)
{
	if (this != &c)
	{
		CopyFrom(c);
	}
	return *this;
}



void Consortium::AddSubcontractor(const StateOwnedCompany& sOC)
{
	Company* cSOC = new StateOwnedCompany(sOC);
	subcontractors.push_back(cSOC);
}

void Consortium::AddSubcontractor(const PrivateCompany& pC)
{
	Company* cPC = new PrivateCompany(pC);
	subcontractors.push_back(cPC);
}

void Consortium::AddSubcontractor(const Consortium& c)
{
	Company* cC = new Consortium(c);
	subcontractors.push_back(cC);
}


bool Consortium::perform(std::string task)
{
	TakeOnANewProject();
	int min = 0;
	
	for (int i = 0;i < subcontractors.size();i++)
	{
		if (subcontractors[i]->getTakenProjects() < subcontractors[min]->getTakenProjects())min = i;
	}
	bool wasASuccess = subcontractors[min]->perform(task);
	if (wasASuccess == true)enterAsSuccess();
	return wasASuccess;
}
double Consortium::reliabilityRate() const
{
	if (getTakenProjects() == 0)return 0;
	return getSuccessfulProjects() /(double) getTakenProjects();
}

void Consortium::deleteSubcontractor(const char* name)
{
	int index = -1;
	for (int i = 0;i < subcontractors.size();i++)
	{
		if(strcmp(subcontractors[i]->getName(),name)==0)
		{
			index = i;
		}
	}
	if (index != -1)
	{
		for (int i = index;i < subcontractors.size() - 1;i++)
		{
			subcontractors[i] = subcontractors[i + 1];
		}
	}
}

void Consortium::printStatus() const
{
	for(int i=0;i<subcontractors.size();i++)
	{
		std::cout << subcontractors[i]->getName()
			<< " reliability : " << subcontractors[i]->reliabilityRate() << std::endl;
	}
}


std::ostream& operator<<(std::ostream& os, const Consortium& c)
{
	os << "Consortium : " << c.getName() << std::endl;
	return os;
}

std::istream& operator>>(std::istream& in, Consortium& c)
{
	in >> (Company&)c;
	return in;
}
