#include <iostream>
using namespace std;

class Appliance 
{
  public:
	void virtual turnOn() = 0;
};

class Fan : public Appliance 
{
  public:
	void turnOn() 
	{
		cout << "Fan starts rotating\n";
	}
};

class AirConditioner : public Appliance 
{
  public:
	void turnOn() 
	{
		cout << "Air Conditioner starts cooling\n";
	}
};

int main() 
{
	Fan fan_object;
	AirConditioner aircon_object;

	fan_object.turnOn();
	aircon_object.turnOn();

	return 0;
}
