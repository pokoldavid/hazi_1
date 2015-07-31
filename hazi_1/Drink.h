#pragma once
#include	"menuItem.h"
#include	<string>
#include	<iostream>

class Drink: public menuItem
{
public:
	Drink();
	Drink(string name, double p, string type);
	string getName() const;
	double getPrice() const;
	void getType() const;
	bool setPrice(const double pr);
	bool setName(const string n);
	bool setType(const string t);
	Drink& operator=(const Drink& other);
	double operator+(const Drink& other);
	bool operator==(const Drink& other);
	void print();
	~Drink();
	friend ostream &operator<<(ostream &os, const Drink &item);

private:
	string	type;
};
