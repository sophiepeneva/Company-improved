# Company-improved

#include "PrivateCompany.h"



PrivateCompany::PrivateCompany(const char* name, int tP, int sP, int sR)
	: Company(name, tP, sP), successRate(sR)
{}

bool PrivateCompany::perform(std::string task)
{
	TakeOnANewProject();
	if (getTakenProjects() % successRate == 0) 
	{
		std::cout << "Operation " << task << " unsuccessful!" << std::endl;
		return false; 
	}
	std::cout << "Operation " << task << " successfully completed by "<<getName()<<"!" << std::endl;
	enterAsSuccess();
	return true;
}


double PrivateCompany::reliabilityRate() const 
{
	if (getTakenProjects() == 0)return 0;
	return getSuccessfulProjects() /(double) getTakenProjects();
}

std::ostream& operator<<(std::ostream& os, const PrivateCompany& pC)
{
	os << "Private company : " << pC.getName() << std::endl;
	return os;
}

std::istream& operator>>(std::istream& in, PrivateCompany& pC)
{
	in >> (Company&)pC;
	std::cout << "Enter the total success rate : " << std::endl;
	in >> pC.successRate;
	return in;
}
