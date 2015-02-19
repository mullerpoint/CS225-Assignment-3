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
#include <iomanip>
#include "Author.hpp"
#include "Elements.hpp"
#include "MediaItems.hpp"

#define DEF_NAME ""
#define DEF_PAGES 0
#define DEF_PRICE 0.00
#define DEF_PUB 1970
#define ELEMENT_ZERO 0

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

	element_num = ELEMENT_ZERO;
	active++;
}


// display all elements
// display only elements with data in them; if no data in object then display empty
void MediaItems::toCout()
{
	//if the hasData flag is not set the item is empty and print nothing
	if (isEmpty() == false);
	// if the has data flag is set the item has some data in it
	else if (isEmpty() == true)
	{
		// display item name if present
		if (name == DEF_NAME);
		else if (name != DEF_NAME)
		{
			std::cout << std::left << std::setw(19) << "Media Item" << " : " << name << std::endl;
		}

		//display author name if present
		if (author_ptr == NULL);
		else if (author_ptr != NULL)
		{
			std::cout << std::left << std::setw(19) << "  Author" << " : " << (*MediaItems::author_ptr).getName() << std::endl;
		}

		//display publication year if set; check if the value is default
		if (pub_year_def == true);
		else if (pub_year_def == false)
		{
			std::cout << std::left << std::setw(19) << "  Pub Year" << " : " << pub_year << std::endl;
		}

		//display page count if present
		if (pages == DEF_PAGES);
		else if (pages != DEF_PAGES)
		{
			std::cout << std::left << std::setw(19) << "  Pages" << " : " << pages << std::endl;
		}

		//display price if set
		if (price == DEF_PRICE);
		else if (price != DEF_PRICE)
		{
			std::cout << std::left << std::setw(19) << "  Price" << " : $" << std::fixed << price << std::endl;
		}

		//display if the item is in print; check for default then prints the value
		if (in_print_def == true);
		else if (in_print_def == false)
		{
			if (in_print == true)
			{
				std::cout << std::left << std::setw(19) << "  Print Status" << " : " << "In Print" << std::endl;
			}
			else if (in_print == false)
			{
				std::cout << std::left << std::setw(19) << "  Print Status" << " : " << "Out of Print" << std::endl;
			}
		}

		//display elements if they exist; 
		if (element_num == ELEMENT_ZERO);
		else if (element_num > ELEMENT_ZERO)
		{
			int count = 0;
			while (count < element_num)
			{
				std::cout << MediaItems::element[count];
				count++;
			}
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
	MediaItems::modified(true);
}

//set book elements
void MediaItems::setElement(int start, int end, std::string name, int elementNum)
//elementNum is not used but I included it to make it easier to change the program over later
{
	element[element_num].setStart(start);
	element[element_num].setEnd(end);
	element[element_num].setName(name);
	MediaItems::modified(true);
	MediaItems::element_num++;	
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