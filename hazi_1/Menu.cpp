#include "Menu.h"

Menu::Menu(){
	foods = NULL;
	drinks = NULL;
	foodsNum = 0;
	drinksNum = 0;
}

Menu::Menu(Food item){
	foodsNum = 1;
	foods[0] = item;
}

Menu::Menu(Drink item){
	drinksNum = 1;
	drinks[0] = item;
}

Menu::Menu(const Food& f, const Drink& d){
	foods = new Food[1];
	drinks = new Drink[1];
	foods[0] = f;
	drinks[0] = d;
	foodsNum = 1;
	drinksNum = 1;
}

bool Menu::addFood(const Food& item)
{
	if (foodsNum == 0)
		Menu(item);
	if (FoodisElement(item))
		return true;
	Food* temp = new Food[foodsNum + 1];
	for (int i = 0; i < foodsNum; i++){
		temp[i] = foods[i];
	}
	temp[foodsNum] = item;
	foodsNum++;
	delete[]foods;
	foods = temp;
	return true;
}

bool Menu::addDrink(const Drink& item){
	if (drinksNum == 0)
		Menu(item);
	if (DrinkisElement(item))
		return true;
	Drink* temp = new Drink[drinksNum + 1];
	for (int i = 0; i < drinksNum; i++){
		temp[i] = drinks[i];
	}
	temp[drinksNum] = item;
	drinksNum++;
	delete[]drinks;
	drinks = temp;
	return true;
}

bool Menu::FoodisElement(const Food& item){
	for (int i = 0; i < foodsNum; i++)
	{
		if (foods[i] == item)
			return true;
	}
	return false;
}

bool Menu::DrinkisElement(const Drink& item){
	for (int i = 0; i < drinksNum; i++){
		if (drinks[i] == item)
			return true;
	}
	return false;
}

Menu::~Menu(){
	delete[]foods;
	delete[]drinks;
	foodsNum = 0;
	drinksNum = 0;
}

void Menu::Print(){
	for (int i = 0; i < foodsNum;i++)
		cout << foods[i];
	for (int i = 0; i < drinksNum;i++)
		cout << drinks[i];
}

double Menu::getPrice(){
	double cost = 0;
	for (int i = 0; i < foodsNum; i++)
		cost = cost + foods[i].getPrice();
	for (int i = 0; i < drinksNum; i++)
		cost = cost + drinks[i].getPrice();
	return cost;
}

ostream &operator<<(ostream &os, const Menu &item) {
	cout << "\tMai menü: " << endl;
	for (int i = 0; i < item.foodsNum; i++){
		cout << item.foods[i];
	}
	for (int i = 0; i < item.drinksNum; i++){
		cout << item.drinks[i];
	}
	return os;
}