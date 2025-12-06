#include "FileOperations.h"
#include <iostream>
/*  مروان هيثم السيد_20246106_G8
	عمر عصام خليفة_20246075_G8
*/
void SaveCompletedOrder(Order *orders, int orderCount)
{

    ofstream file("Completed_orders.txt", ios::app);

    for (int i = 0; i < orderCount; i++)
    {
        if (orders[i].GetStatus() == OrderStatus::Delivered)
        {
            file << orders[i];
            cout << orders[i] << endl;
        }
    }

    file.close();
    cout << "Orders saved to file successfully\n";
}
void SaveDriverStastiscsToFile(DeliveryDriver* drivers[], int drivercount)
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
				cout << "Completed Deliveries: " << drivers[i]->GetCompletedDeliveries() << "\n";
				OutFile << "Total Earnings: " << drivers[i]->GetTotalEarnings() << "\n";
				cout << "Total Earnings: " << drivers[i]->GetTotalEarnings() << "\n";
				double avgearnings = 0;
				if (drivers[i]->GetCompletedDeliveries() > 0)
				{
					avgearnings = drivers[i]->GetTotalEarnings() / drivers[i]->GetCompletedDeliveries();
				}
				OutFile << "Average Earnings Per Delivery: " << avgearnings << "EGP\n";
				cout << "Average Earnings Per Delivery: " << avgearnings << "EGP\n";
				OutFile << "--------------------------------------------------------\n";
				cout << "--------------------------------------------------------\n";
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