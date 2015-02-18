//
//Media Item Class declaration
//

#define DEF_ELEMENTS 15

class MediaItems
{
private:
	std::string name;
	Author* author_ptr;
	Elements element[DEF_ELEMENTS];
	int element_num;
	int pages;

	bool in_print;
	bool in_print_def;

	double price;

	int pub_year;
	bool pub_year_def;

	bool hasData;

	static int active;
public:
	void setName(std::string);
	void setAuthor(Author*);
	void setPages(int);
	void setInPrint(bool);
	void setPrice(double);
	void setPubYear(int);
	void setElement(int, int, std::string, int);
	void toCout();
	void modified(bool);
	bool isEmpty();
	int in_mem();
	MediaItems();
	~MediaItems();

	friend std::ostream& operator<< (std::ostream &out, MediaItems &MI);

};