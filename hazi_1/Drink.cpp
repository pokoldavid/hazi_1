#include	"Drink.h"

using namespace std;
Drink::Drink() : menuItem(){
	type = "Drink";
}
Drink::Drink(string name, double p, string type) : menuItem(name, p), type(type){}
bool Drink::setPrice(const double pr){
	price = pr; return true; }
bool Drink::setName(const string n)
{
	name = n;
	return true;
}
bool Drink::setType(const string t){
	type = t; return true; }

void Drink::print(){
	cout << "Name of the drink:" << "\t" << name << endl;
	cout << "Type:" << "\t" << "\t" << "\t" << type << endl;
	cout << "Costs:" << "\t" << "\t" << "\t" << price << ".-" << endl;
}

Drink& Drink::operator=(const Drink& other){
	this->name = other.name;
	this->type = other.type;
	this->price = other.price;
	return *this;
}

ostream &operator<<(ostream &os, const Drink &item) {
	cout << item.name << "\t\t" << item.type << "\t\t" << "\t" << item.price << ".- Ft" << endl;
	return os;
}

bool Drink::operator==(const Drink& other){
	if (this->name == other.name && this->price == other.price && this->type == other.type)
		return true;
	else
		return false;
}

Drink::~Drink(){}

double Drink::operator+(const Drink& other){
	return this->price + other.price;
}

string Drink::getName() const{ return name; }
double Drink::getPrice() const{ return price; }