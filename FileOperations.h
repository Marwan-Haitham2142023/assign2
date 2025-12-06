#pragma once
#include "Order.h"
#include "DeliveryDriver.h"
#include <fstream>
/*  مروان هيثم السيد_20246106_G8
    عمر عصام خليفة_20246075_G8
*/


void SaveCompletedOrder(Order* orders, int orderCount);
void SaveDriverStastiscsToFile(DeliveryDriver* drivers[], int drivercount);