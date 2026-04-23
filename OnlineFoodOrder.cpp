#include <iostream>
using namespace std;

class OrderStatus 
{
public:
	void virtual showStatus() 
	{
		cout << "Showing Status\n";
	}
};

class Preparing : public OrderStatus 
{
public:
	void showStatus() 
	{
		cout << "Order is being Prepared.\n";
	}
};

class OutForDelivery : public OrderStatus 
{
public:
	void showStatus() 
	{
		cout << "Order is out for delivery.\n";
	}
};

class Delivered : public OrderStatus 
{
public:
	void showStatus() 
	{
		cout << "Order has been delivered. Enjoy!\n";
	}
};

int main() 
{
	OrderStatus* order_pointer;
	Preparing prep_object;
	OutForDelivery delivery_object;
	Delivered delivered_object;

	order_pointer = &prep_object;
	order_pointer->showStatus();

	order_pointer = &delivery_object;
	order_pointer->showStatus();

	order_pointer = &delivered_object;
	order_pointer->showStatus();

	return 0;
}
