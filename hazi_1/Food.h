#pragma	once
#include	"menuItem.h"
#include	<iostream>
#include	<string>

class Food: public menuItem
{
public:
	Food();
	Food(string n, double p, double c, string t);
	string getName() const;
	double getPrice() const;
	bool setName(const string n);
	bool setPrice(const double p);
	bool setType(const string t);
	bool setCal(const double c);
	Food& operator=(const Food& other);
	double operator+(const Food& other);
	bool operator==(const Food& other);
	void print();
	friend ostream &operator<<(ostream &os, const Food &item);
	~Food();
private:
	double	cal;
	string	type;
};
