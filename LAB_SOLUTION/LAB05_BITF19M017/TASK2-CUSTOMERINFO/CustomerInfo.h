#pragma once
class Customer
{
private:
	//pointer array to store name of the customer
	char* name;
	//pointer array to store CNIC of the customer
	char* CNIC; 
	//pointer array to store phone number of the customer
	char* phone;
public:
	//default constructor for customer class to initialize arrays
	Customer();
	//parametrized constructor to initialize array and store values in them
	Customer(char* a_name, char* a_CNIC, char* ph);
	//destructor for classes
	~Customer();
	//method to set name of the customer
	void setName(char* a_name);
	//method to set CNIC of the customer
	bool setCNIC(char* a_CNIC);
	//method to set phone number of the customer
	bool setPhone(char* a_phone);
	//method to return name of the customer
	char* getName() const;
	//method to return CNIC of the customer
	char* getCNIC() const;
	//method to return phone number of the customer
	char* getPhone()const;
	//method tha shows the information of the customer
	void displayCustomerInfo();
};
