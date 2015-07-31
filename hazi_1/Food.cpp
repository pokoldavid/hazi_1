#include	"Food.h"

using namespace std;

Food::Food() : menuItem(){}
Food::Food(string n, double p, double c, string t) : menuItem(n, p), cal(c), type(t){}
Food::~Food(){}
void Food::print()
{
	cout << "Name of the food:" << "\t" << name << endl;
	cout << "Type:" << "\t" << "\t" << "\t"  << type << endl;
	cout << "Calories:" << "\t" << "\t" << cal << "cal" << endl;
	cout << "Costs:" << "\t" << "\t" << "\t" << price << ".-" << endl;
}

Food& Food::operator=(const Food& other){
	this->name = other.name;
	this->type = other.type;
	this->price = other.price;
	this->cal = other.cal;
	return *this;
}

ostream &operator<<(ostream &os, const Food &item) {
	cout << item.name << "\t\t" << item.type << "\t" << item.cal << "cal\t\t" << item.price << ".- Ft" << endl;
	return os;
}

double Food::operator+(const Food& other){
	return this->price + other.price;
}

bool Food::operator==(const Food& other){
	if (this->name == other.name && this->price == other.price && this->cal == other.cal && this->type == other.type)
		return true;
	else
		return false;
}

string Food::getName() const{ return name; }
double Food::getPrice() const{ return price; }
bool Food::setName(const string n){ name = n; return true; }
bool Food::setPrice(const double p){ price = p; return true; }
bool Food::setType(const string t){ type = t; return true; }
bool Food::setCal(const double c){ cal = c; return true; }