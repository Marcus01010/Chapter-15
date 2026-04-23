#include <iostream>
using namespace std;

class Notification 
{
public:
	void virtual sendMessage() 
	{
		cout << "Sending General Notification\n";
	}
};

class EmailNotification : public Notification 
{
public:
	void sendMessage() 
	{
		cout << "Sending Email Notification\n";
	}
};

class SMSNotification : public Notification 
{
public:
	void sendMessage() 
	{
		cout << "Sending SMS Notification\n";
	}
};

int main() 
{
	Notification* notification_pointer;
	EmailNotification email_object;
	SMSNotification sms_object;

	notification_pointer = &email_object;
	notification_pointer->sendMessage();

	notification_pointer = &sms_object;
	notification_pointer->sendMessage();

	return 0;
}
