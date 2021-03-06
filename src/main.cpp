#include <iostream>
#include <string>
#include <sstream>
#include "Material_Derived.h"
#include "Material_Base.h"
#include "Project.h"
#include "SearchTree.h"
#include "crew.h"


int main()
{
	//Project-----------------------------------------------------------------------------------

	Node* rootPtr = NULL;

	Project p;
	std::vector <Project> pVector;

	p.setProjectStatus(); //Set the status to Released to be able to add new projects
	p.getVectorData(pVector);//Add data
	p.anotherObject(pVector);//Prompt user if they wish to add another project
	p.setProjectStatus();//Set the project status to Now Playing to be able to add weekly ticket sales
	p.setTicketSale(pVector);//Add the ticket sales to the correct project (using the project name)

	long double get = p.getTicketSale(); //Everytime a weekly ticket sale is added it gets stored in the variable get
	rootPtr = insert(rootPtr, get); //Which is inserted to the binary tree

	p.displayVector(pVector);//Display the vector of data (including the ticket sales)



	//Material-----------------------------------------------------------------------------------

	int type = 0;
	std::string material;
	std::string specs;



	mType o;//Object of type mType
	Material m;//Object of type Material
	std::vector <Material> mVector;//Object vector of type Material

	o.getMaterialType(type);
	o.getPackagingSpecs();
	material = o.materialType;
	specs = o.packagingSpecifications;
	
	m.getVectorData(mVector, material);
	m.anotherObject(mVector, material);
	m.displayVector(mVector, material, specs);



	//Crew-----------------------------------------------------------------------------------

	Crew c;
	std::vector <Crew> cVector;

	c.getCrewVectorData(cVector);
	c.anotherCrewObject(cVector);
	c.displayCrewVector(cVector);




	//Binary Search Tree-----------------------------------------------------------------------------------

	std::string v;
	long double v_i;

	std::cout << "Enter a ticket sale you would like to search for: " << std::endl;
	//Validation check to see if it's a number
	while (std::cin >> v)
	{
		std::stringstream ss(v);
		if (ss >> v_i)
		{
			if (ss.eof()) //If it successfuly reaches the end of file without encountering an error then the cin operation 
			{   // was a success
				break;
			}
		}
		std::cout << "Please enter a valid number!" << std::endl; //If the entire line could not be successfully converted to an int
	}
	if (search(rootPtr, v_i) == true)
	{
		std::cout << "The value " << v << " has been found." << std::endl;
		std::cout << "\n\n\n";
	}
	else
	{
		std::cout << "The value " << v << " has not been found." << std::endl;
		std::cout << "\n\n\n";
	}

	return 0;

}