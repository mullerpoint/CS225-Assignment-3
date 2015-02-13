//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
// Author Class Implementation
//

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Header Files
#include <iostream>
#include <string>
#include "Author.hpp"


Author::Author()
{
	Author::setBirth(0);
	Author::setDeath(0);
	Author::setName("");
	Author::modified(false);
	active++;
}

void Author::toCout()
{
	if (isEmpty());
	else if (!isEmpty())
	{
		if (birthYear == 0);
		else if (birthYear > 0)
		{
			std::cout << "Birth Year :" << birthYear;
		}
		if (deathYear == 0);
		else if (deathYear > 0)
		{
			std::cout << "Death Year :" << deathYear;
		}
		if (name == "");
		else if (true)
		{
			std::cout << "author name :" << name;
		}
	}
}

Author::~Author()
{
	active--;
}

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

void Author::setName(std::string new_author)
{
	Author::name = new_author;
	Author::modified(true);
}

void Author::modified(bool data)
{
	Author::hasData = data;
}

bool Author::isEmpty()
{
	return hasData;
}

int Author::in_mem()
{
	return active;
}