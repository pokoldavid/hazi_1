#pragma	once
#include	<string>
#include	<iostream>

using namespace std;

class menuItem
{
public:
	menuItem();
	menuItem(string n, double p);
	virtual void print() = 0;
	virtual string getName() const = 0;
	virtual double getPrice() const =0;
	virtual bool setName(const string n) =0;
	virtual bool setPrice(const double p) = 0;
	virtual bool setType(const string t) = 0;
	double operator+(const menuItem& other);
protected:
	string name;
	double price;
};