#include "Customer.h"
Customer:: Customer() :User()
{
	_DeliveryAddress = "";
	_LoyalityPoints = 0;
}
Customer:: Customer(string userId, string name, string phoneNumber, string deliveryaddress, int loyalitypoints)
	:User(userId, name, phoneNumber)
{
	_DeliveryAddress = deliveryaddress;
	_LoyalityPoints = loyalitypoints;
}
void Customer::SetDeliveryAddress(string address)
{
	_DeliveryAddress = address;
}
void Customer::SetLoyalityPoints(int loyalitypoints)
{
	_LoyalityPoints = loyalitypoints;
}
string Customer::GetDeliveryAddress()
{
	return _DeliveryAddress;
}
int Customer::GetLoyalityPoints()
{
	return _LoyalityPoints;
}
void Customer::displayInfo()
{
	cout << "Name: " << Name << endl;
	cout << "Id: " << UserId << endl;
	cout << "Phone Number: " << PhoneNumber << endl;
	cout << "Address: " << _DeliveryAddress << endl;
	cout << "Loyality Points: " << _LoyalityPoints << endl;
}
double Customer:: calculateEarnings()
{
	return _LoyalityPoints * (0.5);
}
Customer &Customer:: operator += (int points)
{
	this->_LoyalityPoints += points;
	return *this;
}
