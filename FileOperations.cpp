#include "FileOperations.h"
#include <iostream>

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