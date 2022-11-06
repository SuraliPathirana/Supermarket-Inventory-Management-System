#include <iostream>
#include <vector>
//#include "stock.h"
//#include "stock.cpp"
using namespace std;

class Employee
{
private:
	string name,username,password;
	int level;
	int joinedday, joinedmonth, joinedyear;
public:
	void getStaffDetails();
	int getRoleNum(string usern,string psword);
	
};

class Floorworker
{
	public:
		void restockAvailableItems(); //restock available items - floor
		void addSupply(); //add items to the supply - floor
};

class Cashier
{
	public:
		void createAndDisplayBill(float totalPrice, int n); //create and display the bill - cashier ,reduce stock
};

class Manager: public Floorworker,public Cashier
{
	public:
		void viewStaff();  //view staff details - manager
		void getOneEmployeeDetails(); //view details of one employee
		void restockNewItems(); //restock available items - manager
		void removeProduct(); //remove items in the stock - manager
		void createInitialStock(); //-manager 	
};

class Owner: public Manager
{
	public:
		//void restockAvailableItems(); //restock available items - floor
		//void viewStaff();  //view staff details - manager
		void deleteStaffMember(); //remove staff members - owner
		//void restockNewItems(); //restock available items - manager
		//void addSupply(); //add items to the supply - floor
		//void createAndDisplayBill(float totalPrice, int n); //create and display the bill - cashier
		void addStaff(); //add staff members - owner
		//void removeProduct(); //remove items in the stock - manager
		//void createInitialStock(); //-manager 
};















/*
class floorworker::public Employee{

};
class Cashier : public Employee
{
public:
    void createAndDisplayBill(float totalPrice, int n);
    void printbill(float totalPrice, int n);
};
class manager : public Cashier
{
    void checkStaffDetails()
    {
        int n;
        cout << "Enter employee number:";
        cin >> n;
        for (int i = 0; i < int(stock.size()); i++)
        {
            if (details[i].getEmployeeNumber() == n)
            {
                cout << "empoylee name:" << details[i].getEmployeeName() << endl;
                cout << "employee ID:" << details[i].getEmployeeNumber() << endl;
                cout << "joined date:" << details[i].getjoinDate() << endl;
                //add  username
            }
        }
    }
    void addItem()
    {
        stock.push_back(Item());
    }
    void removeItem()
    {
        int n;
        cout << "Item serial number:";
        cin >> n;
        for (int i = 0; i < int(stock.size()); i++)
        {
            if (stock[i].getserialnumber() == n)
                stock.erase(stock.begin() + i);
        }
    }
    friend class Owner;
};
class Owner
{
public:
    void removeStaff()
    {
        //destructor for empoyee
    }
    void addStaff()
    {
        //Employee e1;
        //details.push_back(Employee());
    }
};
*/
