# Company-improved

#include "StateOwnedCompany.h"


StateOwnedCompany::StateOwnedCompany(const char* name, int tP, int sP) : Company(name, tP, sP)
{}

bool StateOwnedCompany::perform(std::string task)
{
	TakeOnANewProject();
	if ((getTakenProjects()-1) % 20 != 0)
	{
		std::cout << "Operation " << task << " unsuccessful!" << std::endl;
		return false;
	}
	enterAsSuccess();
	std::cout << "Operation " << task << " successfully completed by " << getName() << "!" << std::endl;
	return true;
}
double StateOwnedCompany::reliabilityRate() const
{
	if (getTakenProjects() == 0)return 0;
	return getSuccessfulProjects() / (double)getTakenProjects();
}


std::ostream& operator<<(std::ostream& os, const StateOwnedCompany& sOC)
{
	os<< "State owned company : " << sOC.getName() << std::endl;
	return os;
}

std::istream& operator>>(std::istream& in, StateOwnedCompany& sOC)
{
	in >> (Company&)sOC;
	return in;
}
