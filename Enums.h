#pragma once
/*  مروان هيثم السيد_20246106_G8
	عمر عصام خليفة_20246075_G8
*/
enum class OrderStatus
{
	pending,
	Preparing,
	Out_For_Delivery,
	Delivered,						//انا زودت دي, انت كنت سايبها
	Cancelled

};
enum class UserType
{
	Customer,
	Driver
};