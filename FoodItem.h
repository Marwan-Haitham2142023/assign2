#pragma once
#include<iostream>
using namespace std;
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

