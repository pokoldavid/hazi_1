#include	"menuItem.h"
#include	<string>
#include	<iostream>


menuItem::menuItem(){
	name = "new item";
	price = 0;
}

menuItem::menuItem(string n, double p) : name(n), price(p){}

double menuItem::operator+(const menuItem& other){
	return this->price + other.price;
}