//
//Author Class declaration
//

class Author
{
private:
	int birthYear;
	int deathYear;
	std::string name;

	bool hasData;

	static int active;

public:
	Author();
	~Author();
	void setBirth(int);
	void setDeath(int);
	void setName(std::string);
	void modified(bool);
	bool isEmpty();
	int in_mem();
	void toCout();
};