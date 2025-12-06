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

Order::Order(string orderId, Customer *customer) 
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

Order::Order(const Order &obj)
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

Order::~Order()
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

void Order::AddItem(const FoodItem &item)
{
    if (_ItemCount >= _Capacity)
    {
        Resize();
    }

    _Items[_ItemCount] = item;
    _ItemCount++;
}

void Order  ::AssignDriver(DeliveryDriver *driver)
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

    if (_Status == OrderStatus::Delivered)
    {

        if (_Status == OrderStatus ::Delivered)
        {
            double orderTotal = CalculateTotal();
            _Driver->CompletedDelivery(orderTotal);
            ++(*_Driver);
            int pointsearned = (int)orderTotal / 10.0;
            *_Customer += pointsearned; // انا مش فاهم اوي نظام ال loyality points فا معرفش ده صح ولا لا
        }
        else
        {
            cout << "There is no driver/customer assigned yet!\n";
        }
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
        cout << (i + 1);
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

string Order::GetOrderId() const
{
    return _OrderId;
}

Customer *Order ::GetCustomer() const
{
    return _Customer;
}
DeliveryDriver *Order ::GetDriver() const
{
    return _Driver;
}
OrderStatus Order ::GetStatus() const
{
    return _Status;
}
int Order ::GetItemCount() const
{
    return _ItemCount;
}

Order &Order ::operator+=(const FoodItem &item)
{

    AddItem(item);

    return *this;
}

Order Order ::operator+(const Order &other) const
{
    if (this->_Customer != nullptr &&
        other._Customer != nullptr &&
        this->_Customer == other._Customer &&
        this->_Driver == other._Driver)
    {
        Order mergedOrder;
        mergedOrder._OrderId = this->_OrderId + other._OrderId;
        mergedOrder._Driver = this->_Driver;
        mergedOrder._Customer = this->_Customer;
        mergedOrder._Status = OrderStatus::pending;

        for (int i = 0; i < this->_ItemCount; i++)
        {
            mergedOrder.AddItem(this->_Items[i]);
        }
        for (int i = 0; i < other._ItemCount; i++)
        {
            mergedOrder.AddItem(other._Items[i]);
        }

        return mergedOrder;
    }
    else
    {
        cout << "Can't merge order! (not the same driver or customer)\n";
        return Order();
    }
}

FoodItem &Order::operator[](int index)
{

    return _Items[index];
}

const FoodItem &Order::operator[](int index) const
{

    return _Items[index];
}

ostream &operator<<(ostream &out, const Order &order)
{

    out << "Order Id : " << order._OrderId << "\tCustomer : ";
    if (order._Customer != nullptr)
        order._Customer->displayInfo();
    else
        out << "Not assigned";
    out << "\nDriver : ";
    if (order._Driver != nullptr)
        order._Driver->displayInfo();
    else
        out << "Not assigned";

    out << "\tItems : ";
    for (int i = 0; i < order._ItemCount; i++)
    {

        order._Items[i].DisplayItem();
        out << endl;
    }

    out << "Order Status : ";
    if (order._Status == OrderStatus::pending)
        out << "Pending";
    else if (order._Status == OrderStatus::Preparing)
        out << "Preparing";
    else if (order._Status == OrderStatus::Out_For_Delivery) // ممكن احولها لفانكشن بره, ايه رأيك؟
        out << "Out For Delivery";
    else if (order._Status == OrderStatus::Delivered)
        out << "Delivered";
    else if (order._Status == OrderStatus::Cancelled)
        out << "Cancelled";

    out << "\tTotal : " << order.CalculateTotal() << " EGP" << endl;

    return out;
}

bool operator>(const Order &order1, const Order &order2)
{

    return order1.CalculateTotal() > order2.CalculateTotal();
}
