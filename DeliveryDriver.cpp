#include "DeliveryDriver.h"
/*  مروان هيثم السيد_20246106_G8
	عمر عصام خليفة_20246075_G8
*/
DeliveryDriver::DeliveryDriver() :User()
{
	_VehicleType = "";
	_CompletedDeliveries = 0;
	_TotalEarnings = 0;
}
DeliveryDriver::DeliveryDriver(string userId, string name, string phoneNumber, string vehicletype, int completeddeliveries, double totalearnings)
	:User(userId, name, phoneNumber)
{
	_VehicleType = vehicletype;
	_CompletedDeliveries = completeddeliveries;
	_TotalEarnings = totalearnings;
}
void DeliveryDriver::SetVehicleType(string type)
{
	_VehicleType = type;
}
void DeliveryDriver::SetCompletedDeliveries(int compdeliveries)
{
	_CompletedDeliveries = compdeliveries;
}
void DeliveryDriver::SetTotalEarnings(double earnings)
{
	_TotalEarnings = earnings;
}
string DeliveryDriver::GetVehicleType()
{
	return _VehicleType;
}
int DeliveryDriver::GetCompletedDeliveries()
{
	return _CompletedDeliveries;
}
double DeliveryDriver::GetTotalEarnings()
{
	return _TotalEarnings;
}
void DeliveryDriver::displayInfo()
{
	cout << "Name: " << Name << endl;
	cout << "Id: " << UserId << endl;
	cout << "Phone Number: " << PhoneNumber << endl;
	cout << "Vehicle type: " << _VehicleType << endl;
	cout << "Completed deliveries: " << _CompletedDeliveries << endl;
	cout << "Total earnings: " << _TotalEarnings << endl;
	if (_CompletedDeliveries > 0)
	{
		cout << "Average earnings per delivery: " << (_TotalEarnings / _CompletedDeliveries) << endl;
	}
	else
	{
		cout << "Average earnings per delivery: 0\n";
	}
}
double DeliveryDriver::calculateEarnings()
{
	return _TotalEarnings;
}
void DeliveryDriver::CompletedDelivery(double ordervalue)
{
	_TotalEarnings += (0.15 * ordervalue);
}
DeliveryDriver& DeliveryDriver:: operator ++()
{
	_CompletedDeliveries++;
	return *this;
}
DeliveryDriver& DeliveryDriver:: operator ++(int)
{
	DeliveryDriver temp = *this;
	_CompletedDeliveries++;
	return temp;
}
 

