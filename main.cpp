#include <iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include "Enums.h"
#include "Customer.h"
#include"DeliveryDriver.h"
#include"User.h"
using namespace std;
void displayMainMenu();
int main()
{
    const int MAX_CUSTOMERS = 100;
    const int MAX_DRIVERS = 50;
    const int MAX_ORDERS = 200;

    Customer** customers = new Customer * [MAX_CUSTOMERS];
    DeliveryDriver** drivers = new DeliveryDriver * [MAX_DRIVERS];
    //Order** orders = new Order * [MAX_ORDERS];

    int customerCount = 0;
    int driverCount = 0;
    int orderCount = 0;


    for (int i = 0; i < MAX_CUSTOMERS; i++) customers[i] = nullptr;
    for (int i = 0; i < MAX_DRIVERS; i++) drivers[i] = nullptr;
    //for (int i = 0; i < MAX_ORDERS; i++) orders[i] = nullptr;

    int choice;

    cout << "========================================\n";
    cout << "   ELMENUS FOOD DELIVERY SYSTEM\n";
    cout << "========================================\n";

    do {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input! Please enter a number.\n";
            continue;
        }

        cin.ignore();
        switch (choice) {
        case 1:
            //createCustomer(customers, customerCount);
            break;
        case 2:
            //createDriver(drivers, driverCount);
            break;
        case 3:
            //createOrder(orders, orderCount, customers, customerCount);
            break;
        case 4:
            //addItemToOrder(orders, orderCount);
            break;
        case 5:
            //assignDriverToOrder(orders, orderCount, drivers, driverCount);
            break;
        case 6:
            //updateOrderStatus(orders, orderCount);
            break;
        case 7:
            //displayAllOrders(orders, orderCount);
            break;
        case 8:
            //displayAllCustomers(customers, customerCount);
            break;
        case 9:
            //displayAllDrivers(drivers, driverCount);
            break;
        case 10:
            //compareOrders(orders, orderCount);
            break;
        case 11:
            //combineOrders(orders, orderCount);
            break;
        case 12:
            //saveCompletedOrders(orders, orderCount);
            break;
        case 13:
            //saveDriverStatistics(drivers, driverCount);
            break;
        case 14:
            //displayStatistics(customers, customerCount, drivers, driverCount);
            break;
        case 15:
            cout << "\nThank you for using ElMenus System!\n";
            break;
        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

        if (choice != 15) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }

    } while (choice != 0);

    //cleanup(customers, customerCount, drivers, driverCount, orders, orderCount);

    delete[] customers;
    delete[] drivers;
    //delete[] orders;
    return 0;
}
       
void displayMainMenu() {
    cout << "\n========================================\n";
    cout << "              MAIN MENU\n";
    cout << "========================================\n";
    cout << "1.  Create Customer\n";
    cout << "2.  Create Delivery Driver\n";
    cout << "3.  Create Order\n";
    cout << "4.  Add Item to Order\n";
    cout << "5.  Assign Driver to Order\n";
    cout << "6.  Update Order Status\n";
    cout << "7.  Display All Orders\n";
    cout << "8.  Display All Customers\n";
    cout << "9.  Display All Drivers\n";
    cout << "10. Compare Two Orders\n";
    cout << "11. Combine Two Orders\n";
    cout << "12. Save Completed Orders to File\n";
    cout << "13. Save Driver Statistics to File\n";
    cout << "14. Display System Statistics\n";
    cout << "15.  Exit\n";
    cout << "========================================\n";
}
