# Company-improved

#include "Consortium.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	StateOwnedCompany soc1("Pirogov hospital",0,0);
	PrivateCompany pc1("Hospital Sofia Med", 0, 0, 2);
	
	Consortium cons1("Burgas hospital consortium");
	Consortium cons2("Sofia hospital consortium");

	cons1.AddSubcontractor(pc1);

	cons2.AddSubcontractor(soc1);
	cons1.AddSubcontractor(cons2);
	string line;
	ifstream projects("projects.txt");
	if (projects.is_open())
	{
		while (getline(projects, line))
		{
			cons1.perform(line);
		}
		projects.close();
	}

	cons1.printStatus();

	system("pause");
}
