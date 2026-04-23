#include <iostream>
#include <string>
using namespace std;

class BillCalculator 
{
  public:
	int calculateBill(int product_price, int shipping_charge) 
	{
		return product_price + shipping_charge;
	}
	double calculateBill(double product_price, double tax_rate) 
	{
		return product_price + (product_price * tax_rate);
	}
	double calculateBill(double product_price, double tax_rate, double discount) 
	{
		return (product_price + (product_price * tax_rate)) - discount;
	}
};

class PaymentMethod 
{
  protected:
	  string customer_name;
	  double amount;
	  string transaction_id;
  public:
	  void virtual pay() = 0;

	  PaymentMethod() 
	  {
		  customer_name = "unknown";
		  amount = 0;
		  transaction_id = "unknown";
	  }

	  void setPaymentDetails(string name, double amount, string id) 
	  {
		  customer_name = name;
		  this->amount = amount;
		  transaction_id = id;
	  }

	  void displayPaymentDetails()
	  {
		  cout << "----- Payment Details -----" << endl;
		  cout << "Customer Name: " << customer_name << endl;
		  cout << "Transaction ID: " << transaction_id << endl;
		  cout << "Amount: " << amount << endl;
	  }
};

class UPIPayment : public PaymentMethod 
{
private:
	string upi_id;
public:
	void setUpiId(string id) 
	{
		upi_id = id;
	}
	void pay() 
	{
		cout << "Payment Method: UPI" << endl;
		cout << "UPI ID: " << upi_id << endl;
		cout << "UPI payment successful" << endl;
	}
};

class CardPayment : public PaymentMethod 
{
private:
	string bank_name;
public:
	void setCardName(string name) 
	{
		bank_name = name;
	}
	void pay() 
	{
		cout << "Payment Method: Card" << endl;
		cout << "Bank Name: " << bank_name << endl;
		cout << "Card payment successful" << endl;
	}
};

class WalletPayment : public PaymentMethod 
{
private:
	string wallet_name;
public:
	void setWalletName(string name)
	{
		wallet_name = name;
	}
	void pay()
	{
		cout << "Payment Method: Wallet" << endl;
		cout << "Wallet Name: " << wallet_name << endl;
		cout << "Wallet payment successful" << endl;
	}
};

int main() 
{
	BillCalculator bill_object;
	PaymentMethod *payment_pointer;
	UPIPayment upi_object;
	CardPayment card_object;
	WalletPayment wallet_object;
	string customername_input; 
	string cardname_input; 
	string walletname_input; 
	string UPI_input;
	int price_input;
	int shipping_input;
	double tax_input; 
	double discount_input;

	cout << "Enter customer name: ";
	getline(cin, customername_input);

	cout << "Enter product price: $";
	cin >> price_input;
	
	cout << "Enter shipping charge: $";
	cin >> shipping_input;

	cout << "Enter tax rate: ";
	cin >> tax_input;

	cout << "Enter discount amount: ";
	cin >> discount_input;

	cin.ignore();
	cout << "Enter UPI id: ";
	getline(cin, UPI_input);

	cout << "Enter bank name: ";
	getline(cin, cardname_input);

	cout << "Enter wallet name: ";
	getline(cin, walletname_input);

	cout << endl;

	int total_with_shipping = bill_object.calculateBill(price_input, shipping_input);
	double total_with_tax = bill_object.calculateBill((double)price_input, tax_input);
	double final_total = bill_object.calculateBill((double)price_input, tax_input, discount_input);

	cout << "----- Bill Details -----" << endl;
	cout << "Customer Name: " << customername_input << endl;
	cout << "Total using product price and shipping: $" << total_with_shipping << endl;
	cout << "Total using product price and tax: $" << total_with_tax << endl;
	cout << "Total using product price, tax, and discount: $" << final_total << endl << endl;

	upi_object.setPaymentDetails(customername_input, final_total, "TXN1001");
	upi_object.setUpiId(UPI_input);

	card_object.setPaymentDetails(customername_input, final_total, "TXN1002");
	card_object.setCardName(cardname_input);

	wallet_object.setPaymentDetails(customername_input, final_total, "TXN1003");
	wallet_object.setWalletName(walletname_input);

	payment_pointer = &upi_object;
	payment_pointer->displayPaymentDetails();
	payment_pointer->pay();
	cout << endl;

	payment_pointer = &card_object;
	payment_pointer->displayPaymentDetails();
	payment_pointer->pay();
	cout << endl;

	payment_pointer = &wallet_object;
	payment_pointer->displayPaymentDetails();
	payment_pointer->pay();
	cout << endl;

	return 0;
}
