#include "DeliveryDriver.h"
/*  ????? ???? ?????_20246106_G8
	??? ???? ?????_20246075_G8
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
 void DeliveryDriver::SaveDriverStastiscsToFile(DeliveryDriver * drivers[],int drivercount)
{
	 ofstream OutFile("driver_stats.txt");
	 if (!OutFile)
	 {
		 cout << "\n Unable to open driver_stats.txt!\n";
		 return;
	 }
	 string Header = "==========================================";
	 Header += "          Delivery Driver Statistics\n";
	 Header += "========================================";
	 OutFile << Header;
	 cout << endl << Header;
	 if (drivercount == 0)
	 {
		 string nodrivers = "No drivers found in the system\n";
		 OutFile << nodrivers;
		 cout << nodrivers;
	 }
	 else
	 {
		 for (int i = 0; i < drivercount; i++)
		 {
			 if (drivers[i] != nullptr)
			 {
				 string driverinfo = "Driver Id: " + drivers[i]->GetUserId() + "\n";
				 driverinfo += "Name: " + drivers[i]->GetName() + "\n";
				 driverinfo += "Phone: " + drivers[i]->GetPhoneNumber() + "\n";
				 driverinfo += "Vehicle Type: " + drivers[i]->GetVehicleType() + "\n";
				 OutFile << driverinfo;
				 cout << driverinfo;
				 OutFile << fixed << setprecision(2);
				 cout << fixed << setprecision(2);
				 OutFile << "Completed Deliveries: " << drivers[i]->GetCompletedDeliveries() << "\n";
				 cout<< "Completed Deliveries: " << drivers[i]->GetCompletedDeliveries() << "\n";
				 OutFile << "Total Earnings: " << drivers[i]->GetTotalEarnings() << "\n";
				 cout<< "Total Earnings: " << drivers[i]->GetTotalEarnings() << "\n";
				 double avgearnings = 0;
				 if (drivers[i]->GetCompletedDeliveries() > 0)
				 {
					 avgearnings = drivers[i]->GetTotalEarnings() / drivers[i]->GetCompletedDeliveries();
				 }
				 OutFile << "Average Earnings Per Delivery: " << avgearnings << "EGP\n";
				 cout<< "Average Earnings Per Delivery: " << avgearnings << "EGP\n";
				 OutFile << "--------------------------------------------------------\n";
				 cout<< "--------------------------------------------------------\n";
			 }
		 }
		 int totalDeliveries = 0;
		 double totalEarnings = 0.0;

		 for (int i = 0; i < drivercount; i++) {
			 if (drivers[i] != nullptr) {
				 totalDeliveries += drivers[i]->GetCompletedDeliveries();
				 totalEarnings += drivers[i]->GetTotalEarnings();
			 }
		 }

		 string summary = "\n========================================\n";
		 summary += "              SUMMARY\n";
		 summary += "========================================\n";

		 OutFile << summary;
		 cout << summary;

		 OutFile << "Total Drivers: " << drivercount << "\n";
		 cout << "Total Drivers: " << drivercount << "\n";

		 OutFile << "Total Deliveries: " << totalDeliveries << "\n";
		 cout << "Total Deliveries: " << totalDeliveries << "\n";

		 OutFile << fixed << setprecision(2);
		 cout << fixed << setprecision(2);

		 OutFile << "Total Earnings: " << totalEarnings << " EGP\n";
		 cout << "Total Earnings: " << totalEarnings << " EGP\n";

		 if (drivercount > 0) {
			 double avgEarningsPerDriver = totalEarnings / drivercount;
			 OutFile << "Average Earnings per Driver: " << avgEarningsPerDriver << " EGP\n";
			 cout << "Average Earnings per Driver: " << avgEarningsPerDriver << " EGP\n";
		 }

		 OutFile << "========================================\n";
		 cout << "========================================\n";
	 }

	 OutFile.close();
	 cout << "\nDriver statistics saved to driver_stats.txt successfully!\n";
 }
	 
