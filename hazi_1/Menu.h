#pragma once
#include "menuItem.h"
#include "Food.h"
#include "Drink.h"

class Menu{
public:
	Menu();
	Menu(Food item);
	Menu(Drink item);
	Menu(const Food& f, const Drink& d);
	~Menu();
	void Print();
	bool addFood(const Food& item);
	bool addDrink(const Drink& item);
	bool FoodisElement(const Food& item);
	bool DrinkisElement(const Drink& item);
	double getPrice();
	friend ostream &operator<<(ostream &os, const Menu &m);
protected:
	Food* foods;
	int foodsNum;
	Drink* drinks;
	int drinksNum;
};