#include "FoodItem.h"
/*  مروان هيثم السيد_20246106_G8
	عمر عصام خليفة_20246075_G8
*/
FoodItem:: FoodItem()
{
	_ItemName = "";
	_Price = 0;
	_Quantity = 0;
};
FoodItem:: FoodItem(string itemname, double price, int quantity)
{
	_ItemName = itemname;
	_Price = price;
	_Quantity = quantity;
}
void FoodItem::SetItemName(string itemname)
{
	_ItemName = itemname;

}
void FoodItem :: SetPrice(double Price)
{
	_Price = Price;
}
void FoodItem::SetQuantity(int Quantity)
{
	_Quantity = Quantity;
}
double FoodItem::CalculateItemTotal()
{
	return _Price * _Quantity;
}
string FoodItem::GetItemName()
{
	return _ItemName;
}
double FoodItem::GetPrice()
{
	return _Price;
}
int FoodItem::GetQuantity()
{
	return _Quantity;
}
void FoodItem::DisplayItem()
{
	cout << _ItemName << " x" << _Quantity << " @ " << _Price << " EGP = " << CalculateItemTotal() << " EGP";
}