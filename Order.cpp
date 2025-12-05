#include "Order.h"

/*  مروان هيثم السيد_20246106_G8
    عمر عصام خليفة_20246075_G8
*/

int Order::_Total_Orders = 0;

Order ::Order()
{
    _OrderId = "Unknown";
    _Customer = nullptr;
    _Driver = nullptr;
    _ItemCount = 0;
    _Capacity = 5;
    _Items = new FoodItem[_Capacity];
    _Status = OrderStatus::pending;
    _Total_Orders++;
}

Order ::Order(string orderId, Customer *customer)
{
    _OrderId = orderId;
    _Customer = customer;
    _Driver = nullptr;
    _ItemCount = 0;
    _Capacity = 5;
    _Items = new FoodItem[_Capacity];
    _Status = OrderStatus::pending;
    _Total_Orders++;
}

Order ::Order(const Order &obj)
{

    _OrderId = obj._OrderId;
    _ItemCount = obj._ItemCount;
    _Capacity = obj._Capacity;
    _Status = obj._Status;

    _Customer = obj._Customer;
    _Driver = obj._Driver;

    _Items = new FoodItem[_Capacity];

    for (int i = 0; i < _ItemCount; i++)
    {
        _Items[i] = obj._Items[i];
    }

    _Total_Orders++;
}

Order ::~Order()
{
    delete[] _Items;
}

void Order ::Resize()
{
    int tempCap = _Capacity * 2;
    FoodItem *tempArr = new FoodItem[tempCap];

    for (int i = 0; i < _ItemCount; i++)
    {

        tempArr[i] = _Items[i];
    }

    delete[] _Items;

    _Items = tempArr;
    _Capacity = tempCap;
}

void Order ::AddItem(const FoodItem &item)
{
    if (_ItemCount >= _Capacity)
    {
        Resize();
    }

    _Items[_ItemCount] = item;
    _ItemCount++;
}

void Order ::AssignDriver(DeliveryDriver *driver)
{
    _Driver = driver;
}

double Order ::CalculateTotal() const
{
    double totalValue = 0;
    for (int i = 0; i < _ItemCount; i++)
    {
        totalValue += _Items[i].CalculateItemTotal();
    }

    return totalValue;
}

void Order ::UpdateStatus(OrderStatus newstatus)
{
    _Status = newstatus;
    if (_Driver != nullptr && _Customer != nullptr)
    {

        if (_Status == OrderStatus ::Delivered)
        {
            double orderTotal = CalculateTotal();
            _Driver->CompletedDelivery(orderTotal);
            *_Customer += orderTotal; // انا مش فاهم اوي نظام ال loyality points فا معرفش ده صح ولا لا
        }
    }
    else
    {
        cout << "There is no driver/customer assigned yet!\n";
    }
}

void Order ::DisplayOrder() const // عايز testing للكلام ده عشان افهم الشكل
{

    cout << "Order Id : " << _OrderId << "\tCustomer : ";
    if (_Customer != nullptr)
        _Customer->displayInfo();
    else
        cout << "Not assigned";
    cout << "\nDriver : ";
    if (_Driver != nullptr)
        _Driver->displayInfo();
    else
        cout << "Not assigned";

    cout << "\tItems : ";
    for (int i = 0; i < _ItemCount; i++)
    {

        _Items[i].DisplayItem();
        cout << endl;
    }

    cout << "Order Status : ";
    if (_Status == OrderStatus::pending)
        cout << "Pending";
    else if (_Status == OrderStatus::Preparing)
        cout << "Preparing";
    else if (_Status == OrderStatus::Out_For_Delivery) // ممكن احولها لفانكشن بره, ايه رأيك؟
        cout << "Out For Delivery";
    else if (_Status == OrderStatus::Delivered)
        cout << "Delivered";
    else if (_Status == OrderStatus::Cancelled)
        cout << "Cancelled";

    cout << "\tTotal : " << CalculateTotal() << " EGP" << endl;
}

int Order ::GetTotalOrders()
{
    return _Total_Orders;
}
