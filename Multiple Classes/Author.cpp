//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Author Class Implementation
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Header Files
#include <iostream>
#include <string>
#include <iomanip>
#include "Author.hpp"


//Defines for default vaules
#define DEF_BIRTH 0
#define DEF_DEATH 0
#define DEF_NAME ""

//Active author objects to start
int Author::active = 0;

//Constructor
Author::Author()
{
	Author::setBirth(DEF_BIRTH);
	Author::setDeath(DEF_DEATH);
	Author::setName(DEF_NAME);
	Author::modified(false);
	active++;
}

//Display all atributes
void Author::toCout()
{
	if (isEmpty());
	else if (!isEmpty())
	{
		if (name == "");
		else if (true)
		{
			std::cout << std::left << std::setw(19) << "Author name" << " : " << name;
		}
		if (birthYear == 0);
		else if (birthYear > 0)
		{
			std::cout << std::left << std::setw(19) << "  Birth Year" << " : " << birthYear;
		}
		if (deathYear == 0);
		else if (deathYear > 0)
		{
			std::cout << std::left << std::setw(19) << "  Death Year" << " : " << deathYear;
		}
	}
}

//destructor
Author::~Author()
{
	active--;
}

//set the birth year
void Author::setBirth(int new_birth)
{
	if (new_birth >= 0)
	{
		Author::birthYear = new_birth;
		Author::modified(true);
	}
	else
	{
		std::cout << "Please enter a valid birth year.";
	}
}

//set the death year
void Author::setDeath(int new_death)
{
	if (new_death >= 0)
	{
		Author::deathYear = new_death;
		Author::modified(true);
	}
	else
	{
		std::cout << "Please enter a valid death year.";
	}
}

//set the author name
void Author::setName(std::string new_author)
{
	Author::name = new_author;
	Author::modified(true);
}

//get the Author Name
std::string Author::getName()
{
	return Author::name;
}

//set author as modified/ unmodified
void Author::modified(bool data)
{
	Author::hasData = data;
}

//object empty check
bool Author::isEmpty()
{
	return hasData;
}

//objects in memory
int Author::in_mem()
{
	return active;
}

std::ostream& operator<<(std::ostream &out, Author &Auth)
{
	out << std::left << std::setw(19) << "  Author" << " : " << Auth.name;
	return out;
}