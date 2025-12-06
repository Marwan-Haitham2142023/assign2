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
void addItemToOrder(Order** orders, int orderCount);
void assignDriverToOrder(Order** orders, int orderCount, DeliveryDriver** drivers, int driverCount);
void updateOrderStatus(Order** orders, int orderCount);
void displayAllOrders(Order** orders, int orderCount);
void displayAllCustomers(Customer** customers, int customerCount);
void displayAllDrivers(DeliveryDriver** drivers, int driverCount);
void compareOrders(Order** orders, int orderCount);
void combineOrders(Order** orders, int& orderCount);
/*void saveCompletedOrders(Order** orders, int orderCount);
void saveDriverStatistics(DeliveryDriver** drivers, int driverCount);
void displayStatistics(Customer** customers, int customerCount, DeliveryDriver** drivers, int driverCount);
void cleanup(Customer** customers, int customerCount, DeliveryDriver** drivers, int driverCount, Order** orders, int orderCount);
*/int main()
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
            addItemToOrder(orders, orderCount);
            break;
        case 5:
            assignDriverToOrder(orders, orderCount, drivers, driverCount);
            break;
        case 6:
            updateOrderStatus(orders, orderCount);
            break;
        case 7:
            displayAllOrders(orders, orderCount);
            break;
        case 8:
            displayAllCustomers(customers, customerCount);
            break;
        case 9:
            displayAllDrivers(drivers, driverCount);
            break;
        case 10:
            compareOrders(orders, orderCount);
            break;
        case 11:
            combineOrders(orders, orderCount);
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

    orders[orderCount] = new Order(orderId, customers[customerChoice -1]);
    orderCount++;

    cout << "\nOrder created successfully!\n";
}
void addItemToOrder(Order** orders, int orderCount) {
    if (orderCount == 0) {
        cout << "\nNo orders available! Please create an order first.\n";
        return;
    }

    cout << "\n--- Add Item to Order ---\n";
    cout << "Available Orders:\n";
    for (int i = 0; i < orderCount; i++) {
        cout << i + 1 << ". Order ID: " << orders[i]->GetOrderId() << "\n";
    }

    int orderChoice;
    cout << "Select order (1-" << orderCount << "): ";
    cin >> orderChoice;
    cin.ignore();

    if (orderChoice < 1 || orderChoice > orderCount) {
        cout << "\nInvalid order selection!\n";
        return;
    }

    string itemName;
    double price;
    int quantity;

    cout << "Enter Item Name: ";
    getline(cin, itemName);
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Quantity: ";
    cin >> quantity;
    cin.ignore();

    if (price < 0 || quantity < 1) {
        cout << "\nInvalid price or quantity!\n";
        return;
    }

    FoodItem item(itemName, price, quantity);
    *orders[orderChoice - 1] += item; // Using operator+=

    cout << "\nItem added successfully!\n";
}

void assignDriverToOrder(Order** orders, int orderCount, DeliveryDriver** drivers, int driverCount) {
    if (orderCount == 0) {
        cout << "\nNo orders available!\n";
        return;
    }

    if (driverCount == 0) {
        cout << "\nNo drivers available! Please create a driver first.\n";
        return;
    }

    cout << "\n--- Assign Driver to Order ---\n";
    cout << "Available Orders:\n";
    for (int i = 0; i < orderCount; i++) {
        cout << i + 1 << ". Order ID: " << orders[i]->GetOrderId() << "\n";
    }

    int orderChoice;
    cout << "Select order (1-" << orderCount << "): ";
    cin >> orderChoice;
    cin.ignore();

    if (orderChoice < 1 || orderChoice > orderCount) {
        cout << "\nInvalid order selection!\n";
        return;
    }

    cout << "\nAvailable Drivers:\n";
    for (int i = 0; i < driverCount; i++) {
        cout << i + 1 << ". " << drivers[i]->GetUserId() << " - "
            << drivers[i]->GetName() << " (" << drivers[i]->GetVehicleType() << ")\n";
    }

    int driverChoice;
    cout << "Select driver (1-" << driverCount << "): ";
    cin >> driverChoice;
    cin.ignore();

    if (driverChoice < 1 || driverChoice > driverCount) {
        cout << "\nInvalid driver selection!\n";
        return;
    }

    orders[orderChoice - 1]->AssignDriver(drivers[driverChoice - 1]);
    cout << "\nDriver assigned successfully!\n";
}

void updateOrderStatus(Order** orders, int orderCount) {
    if (orderCount == 0) {
        cout << "\nNo orders available!\n";
        return;
    }

    cout << "\n--- Update Order Status ---\n";
    cout << "Available Orders:\n";
    for (int i = 0; i < orderCount; i++) {
        cout << i + 1 << ". Order ID: " << orders[i]->GetOrderId() << "\n";
    }

    int orderChoice;
    cout << "Select order (1-" << orderCount << "): ";
    cin >> orderChoice;
    cin.ignore();

    if (orderChoice < 1 || orderChoice > orderCount) {
        cout << "\nInvalid order selection!\n";
        return;
    }

    cout << "\nOrder Status Options:\n";
    cout << "1. PENDING\n";
    cout << "2. PREPARING\n";
    cout << "3. OUT_FOR_DELIVERY\n";
    cout << "4. DELIVERED\n";
    cout << "5. CANCELLED\n";

    int statusChoice;
    cout << "Select new status (1-5): ";
    cin >> statusChoice;
    cin.ignore();

    OrderStatus newStatus;
    switch (statusChoice) {
    case 1: newStatus = OrderStatus::pending; break;
    case 2: newStatus = OrderStatus::Preparing; break;
    case 3: newStatus = OrderStatus::Out_For_Delivery; break;
    case 4: newStatus = OrderStatus::Delivered; break;
    case 5: newStatus = OrderStatus::Cancelled; break;
    default:
        cout << "\nInvalid status selection!\n";
        return;
    }

    orders[orderChoice - 1]->UpdateStatus(newStatus);
    cout << "\nOrder status updated successfully!\n";
}

void displayAllOrders(Order** orders, int orderCount) {
    if (orderCount == 0) {
        cout << "\nNo orders available!\n";
        return;
    }

    cout << "\n--- All Orders ---\n";
    for (int i = 0; i < orderCount; i++) {
        orders[i]->DisplayOrder();
    }
}

void displayAllCustomers(Customer** customers, int customerCount) {
    if (customerCount == 0) {
        cout << "\nNo customers available!\n";
        return;
    }

    cout << "\n--- All Customers ---\n";
    for (int i = 0; i < customerCount; i++) {
        customers[i]->displayInfo();
        cout << endl;
    }
}

void displayAllDrivers(DeliveryDriver** drivers, int driverCount) {
    if (driverCount == 0) {
        cout << "\nNo drivers available!\n";
        return;
    }

    cout << "\n--- All Drivers ---\n";
    for (int i = 0; i < driverCount; i++) {
        drivers[i]->displayInfo();
    }
}

void compareOrders(Order** orders, int orderCount) {
    if (orderCount < 2) {
        cout << "\nNeed at least 2 orders to compare!\n";
        return;
    }

    cout << "\n--- Compare Orders ---\n";
    cout << "Available Orders:\n";
    for (int i = 0; i < orderCount; i++) {
        cout << i + 1 << ". " << *orders[i] << "\n"; // Using operator<<
    }

    int order1, order2;
    cout << "Select first order (1-" << orderCount << "): ";
    cin >> order1;
    cout << "Select second order (1-" << orderCount << "): ";
    cin >> order2;
    cin.ignore();

    if (order1 < 1 || order1 > orderCount || order2 < 1 || order2 > orderCount) {
        cout << "\nInvalid order selection!\n";
        return;
    }

    cout << "\n--- Comparison Result ---\n";
    if (*orders[order1 - 1] > *orders[order2 - 1]) { // Using operator>
        cout << "Order " << orders[order1 - 1]->GetOrderId()
            << " is greater than Order " << orders[order2 - 1]->GetOrderId() << "\n";
    }
    else {
        cout << "Order " << orders[order2 - 1]->GetOrderId()
            << " is greater than or equal to Order " << orders[order1 - 1]->GetOrderId() << "\n";
    }
}

void combineOrders(Order** orders, int& orderCount) {
    if (orderCount < 2) {
        cout << "\nNeed at least 2 orders to combine!\n";
        return;
    }

    cout << "\n--- Combine Orders ---\n";
    cout << "Available Orders:\n";
    for (int i = 0; i < orderCount; i++) {
        cout << i + 1 << ". Order ID: " << orders[i]->GetOrderId() << "\n";
    }

    int order1, order2;
    cout << "Select first order (1-" << orderCount << "): ";
    cin >> order1;
    cout << "Select second order (1-" << orderCount << "): ";
    cin >> order2;
    cin.ignore();

    if (order1 < 1 || order1 > orderCount || order2 < 1 || order2 > orderCount) {
        cout << "\nInvalid order selection!\n";
        return;
    }

    Order combined = *orders[order1 - 1] + *orders[order2 - 1]; // Using operator+
    orders[orderCount] = new Order(combined);
    orderCount++;

    cout << "\nOrders combined successfully! New Order ID: " << combined.GetOrderId() << "\n";
}