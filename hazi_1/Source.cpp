#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <locale>
#include "menuItem.h"
#include "Food.h"
#include "Drink.h"
#include "Menu.h"


int main()
{
	setlocale(LC_ALL, "");

	cout << "\t\t\t\tÉtlap" << endl << endl;
	ifstream t, h;
	string line;
	int q = 0;
		t.open("Food.txt");
		if (t.is_open()){
			while (!t.eof()){
				getline(t, line);
				q++;
			}
		}
		t.close();
	int numberOfFoods;
	numberOfFoods = q / 4;
	Food* foods = new Food[numberOfFoods];
	float x;
	t.open("Food.txt");
	if (t.is_open())
	{
		int i = 0;
		while (getline(t, line))
		{
			foods[i].setName(line);
			getline(t, line);
			foods[i].setType(line);
			t >> x;
			foods[i].setPrice(x);
			t >> x;
			foods[i].setCal(x);
			getline(t, line);
			i++;
		}
		t.close();
	}
	for (int i = 0; i < numberOfFoods; i++){
		cout << foods[i];
	}
	cout << endl << endl;




	cout << "\t\t\t\tItallap" << endl << endl;
	q = 0;
	h.open("Drink.txt");
	if (h.is_open()){
		while (!h.eof()){
			getline(h, line);
			q++;
		}
	}
	h.close();
	int numberOfDrinks = q / 3;
	Drink* drinks = new Drink[numberOfDrinks];
	h.open("Drink.txt");
	if (h.is_open())
	{
		int i = 0;
		while (getline(h, line))
		{
			drinks[i].setName(line);
			getline(h, line);
			drinks[i].setType(line);
			h >> x;
			drinks[i].setPrice(x);
			i++;
			getline(h, line);
		}
		h.close();
	}
	for (int i = 0; i < numberOfDrinks; i++){
		cout << drinks[i];
	}
	cout << endl;
	Menu mai_menu;
	mai_menu.addFood(foods[2]);
	mai_menu.addFood(foods[12]);
	mai_menu.addFood(foods[2]);
	mai_menu.addDrink(drinks[0]);
	cout << mai_menu;
	cout << endl << endl;


	string order;
	int answer = 1;
	double cost = 0;
	cout << "Felvehetem a rendelést? " << endl;
	cin >> order;
	while (order != "Igen" && order != "Nem")
	{
		cout << "'Igen' vagy 'Nem'?";
		cin >> order;
	}
	if (order == "Nem")
		answer = 0;
	if (order == "Igen")
	{
		cout << "Ajánlhatom a mai menüt?";
		cin >> order;
	}
	if (order != "Igen")
	{
		if (answer == 1)
		{
			cout << "Milyen ételt választott? ";
			cin >> order;
		}
		while (answer)
		{
			for (int i = 0; i < numberOfFoods; i++)
			{
				if (order == foods[i].getName()){
					cost = cost + foods[i].getPrice();
					i = numberOfFoods;
				}
				else
				{
					if (i == numberOfFoods - 1)
						cout << "Ez nem szerepel a listán" << endl;
				}
			}
			cout << "Más valamit esetleg? ";
			cin >> order;
			if (order == "Nem")
				answer = 0;
		}

		answer = 1;
		cout << "Valami italt? " << endl;
		cin >> order;
		while (order != "Igen" && order != "Nem")
		{
			cout << "'Igen' vagy 'Nem'?";
			cin >> order;
		}
		if (order == "Igen"){
			answer = 1;
			cout << "Milyen italt választott? ";
			cin >> order;
		}
		if (order == "Nem")
			answer = 0;
		while (answer)
		{
			for (int i = 0; i < numberOfDrinks; i++)
			{
				if (order == drinks[i].getName()){
					cost = cost + drinks[i].getPrice();
					i = numberOfDrinks;
				}
				else
				{
					if (i == numberOfDrinks - 1)
						cout << "Ez nem szerepel a listán!" << endl;
				}
			}
			cout << "Még valamit esetleg? ";
			cin >> order;
			if (order == "Nem")
				answer = 0;
		}
		if (cost == 0)
			cout << "Késõbb visszajövök!" << endl;

		else{
			cout << endl << "Az összesen: " << cost;
		}
	}
	else
	{
		cout << endl << "Az összesen: " << mai_menu.getPrice();
	}

	cout << endl << endl;
	cout << endl << endl;

	delete[] foods;
	delete[] drinks;
	system("pause");
}