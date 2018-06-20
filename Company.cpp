# Company-improved

#include "Company.h"


Company::Company(const char* name, int tP, int sP) : takenProjects(tP), successfulProjects(sP)
{
	setName(name);
}

Company& Company::operator=(const Company&c)
{
	if (this != &c)
	{
		delete[] name;
		CopyFrom(c);
	}
	return *this;
}

void Company::CopyFrom(const Company& c)
{
	takenProjects = c.takenProjects;
	successfulProjects = c.successfulProjects;
	setName(c.name);
}

void Company::setName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

std::istream& operator>>(std::istream& in, Company& c)
{
	std::cout << "Enter a name for the private company : " << std::endl;
	in >>c.name;
	std::cout << "Enter the total amount of taken projects : " << std::endl;
	in >> c.takenProjects;
	std::cout << "Enter the total amount of successful projects : " << std::endl;
	in >> c.successfulProjects;
	return in;
}
