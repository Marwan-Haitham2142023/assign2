#pragma once
#include<iostream>
using namespace std;
/*  مروان هيثم السيد_20246106_G8
	عمر عصام خليفة_20246075_G8
*/
class FoodItem
{
private:
	string _ItemName;
	double _Price;
	int _Quantity;
public:
	FoodItem();

		FoodItem(string itemname, double price, int quantity);

		void SetItemName(string itemname);

		void SetPrice(double Price);

		void SetQuantity(int Quantity);

		double CalculateItemTotal();

		string GetItemName();

		double GetPrice();

		int GetQuantity();

		void DisplayItem();
	
};

