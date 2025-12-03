#pragma once
#include"User.h"
class Customer : public User
{
	string _DeliveryAddress;
	int _LoyalityPoints;
public:
	Customer();

	Customer(string userId, string name, string phoneNumber, string deliveryaddress, int loyalitypoints=0);
	
	void SetDeliveryAddress(string address);

		void SetLoyalityPoints(int loyalitypoints);

		string GetDeliveryAddress();

		int GetLoyalityPoints();

		void displayInfo();

		double calculateEarnings();

		Customer& operator += (int points);

};

