#pragma once
#include <string>
#include "Customer.h"
#include "DeliveryDriver.h"
#include"FoodItem.h"
#include "Enums.h"
#include <fstream>
using namespace std;
/*  مروان هيثم السيد_20246106_G8
    عمر عصام خليفة_20246075_G8
*/
class Order
{
private:
	string _OrderId;
	Customer* _Customer;
	DeliveryDriver* _Driver;
	FoodItem* _Items;
	int _ItemCount,_Capacity;
	OrderStatus _Status;
	static int _Total_Orders;
	void Resize();
public:
	Order();
	Order(string orderId, Customer *customer);
	Order(const Order& obj);
	~Order();
	void AddItem(const FoodItem& item);
	void AssignDriver(DeliveryDriver* driver);
	void UpdateStatus(OrderStatus newstatus);
	double CalculateTotal() const;
	void DisplayOrder() const;

	static int GetTotalOrders();
	std::string GetOrderId() const;
	Customer* GetCustomer() const;
	DeliveryDriver* GetDriver() const;
	OrderStatus GetStatus() const;
	int GetItemCount() const;
	Order& operator+=(const FoodItem& item);                    
	Order operator+(const Order& other) const;                  
	FoodItem& operator[](int index);                            
	const FoodItem& operator[](int index) const;                

	
	friend ostream& operator<<(ostream& out, const Order& order);
	friend bool operator>(const Order& order1, const Order& order2);

	

};

