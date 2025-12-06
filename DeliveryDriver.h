#pragma once
#include"User.h"
#include<iomanip>
#include <fstream>
/*  مروان هيثم السيد_20246106_G8
	عمر عصام خليفة_20246075_G8
*/
class DeliveryDriver: public User
{
	string _VehicleType;
	int _CompletedDeliveries;
	double _TotalEarnings;
	
public:
	DeliveryDriver();
	DeliveryDriver(string userId, string name, string phoneNumber, string vehicletype, int completeddeliveries, double totalearnings);
		
	void SetVehicleType(string type);
	
	void SetCompletedDeliveries(int compdeliveries);

	void SetTotalEarnings(double earnings);

	string GetVehicleType();
	
	int GetCompletedDeliveries();
	
	double GetTotalEarnings();
	
	void displayInfo();

	double calculateEarnings();
	
	void CompletedDelivery(double ordervalue);
	
	DeliveryDriver& operator ++();

	DeliveryDriver& operator ++(int);
	
	
};

