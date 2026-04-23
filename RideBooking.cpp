#include <iostream>
using namespace std;

class Ride 
{
public:
	void virtual bookRide() = 0;
};

class BikeRide : public Ride 
{
public:
	void bookRide() 
	{
		cout << "Bike ride booked successfully.\n";
	}
};

class CarRide : public Ride 
{
public:
	void bookRide() 
	{
		cout << "Car ride booked successfully.\n";
	}
};

int main() 
{
	Ride* ride_pointer;
	BikeRide bike_object;
	CarRide car_object;

	ride_pointer = &bike_object;
	ride_pointer->bookRide();

	ride_pointer = &car_object;
	ride_pointer->bookRide();

	return 0;
}
