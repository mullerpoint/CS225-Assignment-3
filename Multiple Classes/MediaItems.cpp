//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Media Item Class Implementation
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Header Files
#include <iostream>
#include <string>
#include "Author.hpp"
#include "Elements.hpp"
#include "MediaItems.hpp"

#define DEF_NAME ""
#define DEF_PAGES 0
#define DEF_PRICE 0.00
#define DEF_PUB 1970
#define DEF_ELEMENT 0

//active mediaitem objects to start
int MediaItems::active = 0;

//Constructor - set name/author blank, pages/price to 0, and inprint/pubyear to default = true
MediaItems::MediaItems()
{
	MediaItems::setName(DEF_NAME);
	MediaItems::setAuthor(NULL);
	MediaItems::setPages(DEF_PAGES);

	MediaItems::setInPrint(false);
	in_print_def = true;

	MediaItems::setPrice(DEF_PRICE);

	MediaItems::setPubYear(DEF_PUB);
	pub_year_def = true;

	MediaItems::modified(false);

	element_num = 0;
	active++;
}


// display all elements
// display only elements with data in them; if no data in object then display empty
void MediaItems::toCout()
{
	std::ostream &str;
	//if the hasData flag is not set the item is empty
	if (isEmpty() == false)
	{
		std::cout << "This item is empty" << std::endl;
		str << "This item is empty";
	}
	// if the has data flag is set the item has some data in it
	else if (isEmpty() == true)
	{
		// display item name if present
		if (name == DEF_NAME);
		else if (name != DEF_NAME)
		{
			str << "  Media Item : " << name << std::endl;
		}

		//display author name if present
		if (author_ptr == NULL);
		else if (author_ptr != NULL)
		{
			std::cout << "      Author : " << (*MediaItems::author_ptr).getName() << std::endl;
		}

		//display page count if present
		if (pages == DEF_PAGES);
		else if (pages != DEF_PAGES)
		{
			std::cout << "       Pages : " << pages << std::endl;
		}

		//display price if set
		if (price == DEF_PRICE);
		else if (price != DEF_PRICE)
		{
			std::cout << "       Price : $" << std::fixed << price << std::endl;
		}

		//display if the item is in print; check for default then prints the value
		if (in_print_def == true);
		else if (in_print_def == false)
		{
			if (in_print == true)
			{
				std::cout << "Print Status : " << "True" << std::endl;
			}
			else if (in_print == false)
			{
				std::cout << "Print Status : " << "False" << std::endl;
			}
		}

		//display publication year if set; check if the value is default
		if (pub_year_def == true);
		else if (pub_year_def == false)
		{
			std::cout << "    Pub Year : " << pub_year << std::endl;
		}
	}
}


//set title of book
void MediaItems::setName(std::string new_name)
{
	MediaItems::name = new_name;
	MediaItems::modified(true);
}

//set book author
void MediaItems::setAuthor(Author* new_author)
{
	MediaItems::author_ptr = new_author;
}

//set book elements
void MediaItems::setElement(int start, int end, std::string name, int elementNum)
{
	element[elementNum].setStart(start);
	element[elementNum].setEnd(end);
	element[elementNum].setName(name);
	elementNum++;
}


//set book page count - validate that the book doesnt have a negative page count
void MediaItems::setPages(int new_pages)
{
	if (new_pages >= 0)
	{
		MediaItems::pages = new_pages;
		MediaItems::modified(true);
	}
	else
	{
		std::cout << "Please enter a valid positive page number.";
	}

}

//set book in print status
void MediaItems::setInPrint(bool printStatus)
{
	in_print = printStatus;
	in_print_def = false;
	MediaItems::modified(true);
}

//set the book price - validate that the price is not negative
void MediaItems::setPrice(double new_price)
{
	if (new_price >= 0)
	{
		MediaItems::price = new_price;
		MediaItems::modified(true);
	}
	else
	{
		std::cout << "Please enter a valid positive price.";
	}
}

// set the publication year - validates that the book was not published in a negative year
void MediaItems::setPubYear(int new_year)
{
	if (new_year >= 0)
	{
		MediaItems::pub_year = new_year;
		MediaItems::pub_year_def = false;
		MediaItems::modified(true);
	}
	else
	{
		std::cout << "Please enter a valid Year.";
	}
}

// set a modified flag
void MediaItems::modified(bool data)
{
	MediaItems::hasData = data;
}

bool MediaItems::isEmpty()
{
	return hasData;
}

MediaItems::~MediaItems()
{
	active--;
}

int MediaItems::in_mem()
{
	return active;
}

std::ostream& operator<<(std::ostream &out, MediaItems &MI)
{
	out = MI.toCout;
	return out;
}