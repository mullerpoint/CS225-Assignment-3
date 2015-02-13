//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
// Media Item Class Implementation
//

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Header Files
#include <iostream>
#include <string>
#include "MediaItems.hpp"

//initial items active
int MediaItems::active = 0;

//Constructor - set name/author blank, pages/price to 0, and inprint/pubyear to default = true
MediaItems::MediaItems()
{
	MediaItems::setName("");
	//MediaItems::setAuthor("");
	MediaItems::setPages(0);

	MediaItems::setInPrint(false);
	in_print_def = true;

	MediaItems::setPrice(0.00);

	MediaItems::setPubYear(1970);
	pub_year_def = true;

	MediaItems::modified(false);

	active++;
}


// display all elements
// display only elements with data in them; if no data in object then display empty
void MediaItems::toCout()
{
	//if the hasData flag is not set the item is empty
	if (isEmpty() == false)
	{
		std::cout << "This item is empty" << std::endl;
	}
	// if the has data flag is set the item has some data in it
	else if (isEmpty() == true)
	{
		// display item name if present
		if (name == "");
		else if (name != "")
		{
			std::cout << "  Media Item : " << name << std::endl;
		}

		//display author name if present
		/*if (author == "");
		else if (author != "")
		{
			std::cout << "      Author : " << author << std::endl;
		}*/

		//display page count if present
		if (pages == 0);
		else if (pages != 0)
		{
			std::cout << "       Pages : " << pages << std::endl;
		}

		//display price if set
		if (price == 0.00);
		else if (price != 0.00)
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
//void MediaItems::setAuthor(std::string new_author)
//{
//	MediaItems::author = new_author;
//	MediaItems::modified(true);
//}

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