#pragma once
#include"User.h"
#include<iomanip>
#include <fstream>
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
	
	void SaveDriverStastiscsToFile(DeliveryDriver * drivers[],int drivercount);
};

