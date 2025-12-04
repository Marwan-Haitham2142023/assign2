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
    } while (choice != 0);
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
    cout << "0.  Exit\n";
    cout << "========================================\n";
}
