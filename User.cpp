#include"User.h"
int User::_Total_Users = 0;
User::User()
{
    UserId = "";
    Name = "";
    PhoneNumber = "";
    _Total_Users++;
}
User::User(string userId, string name, string phoneNumber) {
    this->UserId = userId;
    this->Name = name;
    this->PhoneNumber = phoneNumber;
    _Total_Users++;
}
void User::SetUserId(string userid)
{
    UserId = userid;
}
void User:: SetName(string name)
{
    Name = name;
}
void User:: SetPhoneNumber(string phonenum)
{
    PhoneNumber = phonenum;
}
string User:: GetUserId() { return UserId; }
string User:: GetName() { return Name; }
string User:: GetPhoneNumber() { return PhoneNumber; }
 User:: ~User() {
    _Total_Users--;
}