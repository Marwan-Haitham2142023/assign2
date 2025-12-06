#pragma once
#include<iostream>
#include"FoodItem.h"
using namespace std;
/*  مروان هيثم السيد_20246106_G8
    عمر عصام خليفة_20246075_G8
*/
 class User
{
protected:
	string UserId,Name,PhoneNumber;                     // اشمعنى دول مفيش _ قبلهم؟
	static int _Total_Users;
    static int getTotalUsers();                        // ده ليه protected؟
       ;                            // مش المفروض الreturn بتاعها يكون في ال .cpp ؟


public:
    User();

    User(string userId, string name, string phoneNumber);

    void SetUserId(string userid);

    void SetName(string name);
    void SetPhoneNumber(string phonenum);
    string GetUserId();
    string GetName();
    string GetPhoneNumber();
    static int getTotalUsers();

    virtual void displayInfo() = 0;
    virtual double calculateEarnings() = 0;
    virtual ~User();


};

