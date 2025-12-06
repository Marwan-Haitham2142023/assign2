#include <iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include "Enums.h"
#include "Customer.h"
#include"DeliveryDriver.h"
#include"User.h"
#include"Order.h"
using namespace std;
void displayMainMenu();
void createCustomer(Customer** customers, int& customerCount);
void createDriver(DeliveryDriver** drivers, int& driverCount);
void createOrder(Order** orders, int& orderCount, Customer** customers, int customerCount);
int main()
{
    const int MAX_CUSTOMERS = 100;
    const int MAX_DRIVERS = 50;
    const int MAX_ORDERS = 200;

    Customer** customers = new Customer * [MAX_CUSTOMERS];
    DeliveryDriver** drivers = new DeliveryDriver * [MAX_DRIVERS];
    Order** orders = new Order * [MAX_ORDERS];

    int customerCount = 0;
    int driverCount = 0;
    int orderCount = 0;


    for (int i = 0; i < MAX_CUSTOMERS; i++) customers[i] = nullptr;
    for (int i = 0; i < MAX_DRIVERS; i++) drivers[i] = nullptr;
    for (int i = 0; i < MAX_ORDERS; i++) orders[i] = nullptr;

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
            createCustomer(customers, customerCount);
            break;
        case 2:
            createDriver(drivers, driverCount);
            break;
        case 3:
            createOrder(orders, orderCount, customers, customerCount);
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

    } while (choice != 15);

    //cleanup(customers, customerCount, drivers, driverCount, orders, orderCount);

    delete[] customers;
    delete[] drivers;
    delete[] orders;
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
void createCustomer(Customer** customers, int& customerCount) {
    string userId, name, phoneNumber, address;

    cout << "\n--- Create New Customer ---\n";
    cout << "Enter Customer ID: ";
    getline(cin, userId);
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Phone Number: ";
    getline(cin, phoneNumber);
    cout << "Enter Delivery Address: ";
    getline(cin, address);

    customers[customerCount] = new Customer(userId, name, phoneNumber, address, 0);
    customerCount++;

    cout << "\nCustomer created successfully!\n";
}
void createDriver(DeliveryDriver** drivers, int& driverCount) {
    string userId, name, phoneNumber, vehicleType;

    cout << "\n--- Create New Delivery Driver ---\n";
    cout << "Enter Driver ID: ";
    getline(cin, userId);
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Phone Number: ";
    getline(cin, phoneNumber);
    cout << "Enter Vehicle Type: ";
    getline(cin, vehicleType);

    drivers[driverCount] = new DeliveryDriver(userId, name, phoneNumber, vehicleType, 0, 0.0);
    driverCount++;

    cout << "\nDriver created successfully!\n";
}
void createOrder(Order** orders, int& orderCount, Customer** customers, int customerCount) {
    if (customerCount == 0) {
        cout << "\nNo customers available! Please create a customer first.\n";
        return;
    }

    cout << "\n--- Create New Order ---\n";
    cout << "Available Customers:\n";
    for (int i = 0; i < customerCount; i++) {
        cout << i + 1 << ". " << customers[i]->GetUserId() << " - "
            << customers[i]->GetName() << "\n";
    }

    int customerChoice;
    cout << "Select customer (1-" << customerCount << "): ";
    cin >> customerChoice;
    cin.ignore();

    if (customerChoice < 1 || customerChoice > customerCount) {
        cout << "\nInvalid customer selection!\n";
        return;
    }

    string orderId;
    cout << "Enter Order ID: ";
    getline(cin, orderId);

    orders[orderCount] = new Order(orderId, customers[customerChoice ]);
    orderCount++;

    cout << "\nOrder created successfully!\n";
}
