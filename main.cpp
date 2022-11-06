#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "stock.h"
#include "employee.h"
#include "supply.h"

using namespace std;


int main()
{
	//Owner a;
	//a.addSupply();
	//createProducts();
	string username, password, role;
    int access, level;
    //string role;
    //login screen
    system("cls");
    cout << "\n\n\n\n"
            "\t\t**************Welcome to the computerized inventory of ABC supermarket************\n\n\n"
            "\t\t\tPlease enter your login details\n\n\n"
            "\t\t\tUsername- ";
    cin >> username;
    cout << "\t\t\tPassword- ";
    cin >> password;
    Floorworker f1;
    Cashier c1;
    Manager m1;
    Owner o1;
    Employee temp;
    
	access = temp.getRoleNum(username,password); 
    cout<<access;
    
    while (access < 1)
    {
        cout << "\n\n\t\tInvalid user login details!Please enter your details again.\n\n\n" << endl;
        cout<<"\t\t\tUsername- ";
        cin >> username;
        cout << "\t\t\tPassword- ";
        cin >> password;
    }
	/*
    if (access == 1) 
    {
        //floorworker f1;
        role = "floorworker";
    }
    if (access == 2)
    {
        //Cashier c1;
        role = "cashier";
    }
    if (access == 3)
    {
        // manager m1;
        role = "manager";
    }
    if (access == 4)
    {
        //Owner o1;
        role = "owner";
    }
	*/
    system("cls");
    cout << "\n\n\n\t\t\t----------------Welcome!----------------"<< endl;
    //cout << "\n\n\n\t\t\t----------------Welcome!----------------" << username << role << endl;
    switch (access)
    {
    case 1:
    { //floor worker-f1
        int l;
        cout<<"\n\n\n\t\t\t\t\t";
        cout << "1-stock" << endl;
        cout<<"\n\t\t\t\t\t";
        cout << "2-supply" << endl;
        cout<<"\n\t\t\t\t\t";
        cout << "3-exit" << endl;
        cout<<"\n\n\n\n\n\t\t\t";
        cout<<"Enter the number of the section: ";
        cin >> l;
        switch (l)
        {

        case 1: //stock
        {
            int x;
            system("cls");
            cout << "\n\n\n\t\t\t\t----------------addstock----------------"<<endl;
			cout<<"\n\t\t(increase already available items in the stock from supply )"<< endl;
			cout<<"\n\n\n\n\t\t*press 1 to continue:";
            cin >> x;
            if(x==1)
            	f1.restockAvailableItems();
            else
            	cout<<"invalid input!"<<endl;
            break;
        }
        
        case 2: //supply
        {	
        	system("cls");
        	int x;
            cout <<"\n\n\n\t\t\t\t----------------addsupply----------------"<< endl;
            cout<<"\n\n\n\n\t\t*press 1 to continue:";
            cin >> x;
            if(x==1)
            	f1.addSupply();
            else
            	cout<<"invalid input!"<<endl;
            break;
        }
        
        case 3:
        {
            exit(0);
        }
        
    	}
        ;
        break;
    }
	
    case 2:
    { //cashier
    	system("cls");
        int l;
        cout<<"\n\n\n\t\t\t\t\t";
        cout << "1-stock" << endl;
        cout<<"\n\t\t\t\t\t";
        cout << "2-supply" << endl;
        cout<<"\n\t\t\t\t\t";
        cout << "3.exit" << endl;
        cout<<"\n\n\n\n\n\t\t\t";
        cout<<"Enter the number of the section: ";
        cin >> l;
        switch (l)
        { 

        case 1: //stock
        {	
        	system("cls");
        	cout << "\n\n\n\t\t\t\t----------------createBill----------------"<<endl;
            int x;
            cout<<"\n\n\n\n\t\t*press 1 to continue:";
            cin >> x;
            if(x==1)
            	c1.createAndDisplayBill(0,0);
            else
            	cout<<"invalid input!"<<endl;
            break;
        }
        case 2: //supply
        {	
        	system("cls");
            int x;
            cout << "\n\n\n\t\t\t\t----------------createBill----------------"<<endl;
            cout<<"\n\n\n\n\t\t*press 1 to continue:";
            cin >> x;
            if(x==1)
            	c1.createAndDisplayBill(0,0);
            else
            	cout<<"invalid input!"<<endl;
            break;
        }
        case 3:
        {
            exit(0);
        }
        }
        ;
        break;
    }

    case 3:
    { //manager
		system("cls");
        int l;
		cout<<"\n\n\n\t\t\t\t\t";
        cout << "1.stock" << endl;
        cout<<"\n\t\t\t\t\t";
        cout << "2.supply" << endl;
        cout<<"\n\t\t\t\t\t";
        cout << "3.staff" << endl;
        cout<<"\n\t\t\t\t\t";
        cout << "4.exit" << endl;
        cout<<"\n\n\n\n\n\t\t\t";
        cout<<"Enter the number of the section: ";
        cin >> l;
        switch (l)
        {
        case 1:
        {
        	system("cls");
            int x;
            cout << "\n\n\n\t\t\t\t----------------1.restock available items----------------"<<endl;
            cout << "\n\n\n\t\t\t\t----------------2.restock new items----------------"<<endl;
            cout << "\n\n\n\t\t\t\t----------------3.create and display bill----------------"<<endl;
            cout << "\n\n\n\t\t\t\t----------------4.remove items in the stock----------------"<<endl;
            cout<<"\n\n\n\n\t\t*Enter the number of the section: ";
            cin >> x;
            switch (x)
            {
            case 1:
            {
                m1.restockAvailableItems();
                break;
            }
            case 2:
            {
                m1.restockNewItems();
                break;
            }
            case 3:
            {
                m1.createAndDisplayBill(0,0);
                break;
            }
            case 4:
            {
                m1.removeProduct();
                break;
            }
            default:
            {
                cout << "invalid input!";
            } //option to go back to the main menue
            }

            ;
            break;
        }
        case 2:
        {
        	system("cls");
            int x;
            cout << "\n\n\n\t\t\t\t----------------addSupply----------------"<<endl;
            cout<<"\n\n\n\n\t\t*press 1 to continue:";
            cin >> x;
            if(x==1)
            	m1.addSupply();
            else
            	cout<<"invalid input!"<<endl;
            break;
        }
        case 3:
        {
        	system("cls");
            int x;
            cout << "\n\n\n\t\t\t\t----------------1.view all employee details----------------"<<endl;
            cout << "\n\n\n\t\t\t\t----------------2.view one employee details----------------"<<endl;
            cout<<"\n\n\n\n\t\t*Enter the number of the section: ";
            cin>>x;
            switch (x)
            {
            case 1:
            {
                m1.viewStaff();
                break;
            }
            case 2:
            {
                m1.getOneEmployeeDetails();
                break;
            }
            default:
            {
                cout << "Invalid input";
                break;
            } //option to go back
            }
            ;
            break;
        }
        case 4:
        {
			exit(0);
        }
        }
        ;
        break;
    }
    case 4:
    { //owner
    	system("cls");
        int l;
        cout<<"\n\n\n\t\t\t\t\t";
        cout << "1.stock" << endl;
        cout<<"\n\t\t\t\t\t";
        cout << "2.supply" << endl;
        cout<<"\n\t\t\t\t\t";
        cout << "3.staff" << endl;
        cout<<"\n\t\t\t\t\t";
        cout << "4.exit" << endl;
        cout<<"\n\n\n\n\n\t\t\t";
        cout<<"Enter the number of the section: ";
        cin >> l;

        switch (l)
        {
        case 1:
        {
        	system("cls");
            int x;
            cout << "\n\n\n\t\t\t\t----------------1.restock available items----------------"<<endl;
            cout << "\n\n\n\t\t\t\t----------------2.restock new items----------------"<<endl;
            cout << "\n\n\n\t\t\t\t----------------3.create and display bill----------------"<<endl;
            cout << "\n\n\n\t\t\t\t----------------4.remove items in the stock----------------"<<endl;
            cout << "\n\n\n\t\t\t\t----------------5.create the initial stock----------------"<<endl;
            cout<<"\n\n\n\n\t\t*Enter the number of the section: ";
            cin >> x;
            switch (x)
            {
            case 1:
            {
                o1.restockAvailableItems();
                break;
            }
            case 2:
            {
                o1.restockNewItems();
                break;
            }
            case 3:
            {
                o1.createAndDisplayBill(0,0);
                break;
            }
            case 4:
            {
                o1.removeProduct();
                break;
            }
            case 5:
            {
                o1.createInitialStock();
                break;
            }
            default:
            {
                cout << "invalid input!";
            } //option to go back to the main menue
            }

            ;
            break;
        }

        case 2:
        {
        	system("cls");
            int x;
            cout << "\n\n\n\t\t\t\t----------------addSupply----------------"<<endl;
            cout<<"\n\n\n\n\t\t*press 1 to continue:";
            cin >> x;
            if(x==1)
            	o1.addSupply();
            else
            	cout<<"invalid input!"<<endl;
            break;
        }
        case 3:
        {
        	system("cls");
            int x;
            cout << "\n\n\n\t\t\t\t----------------1.view all employee details----------------"<<endl;
            cout << "\n\n\n\t\t\t\t----------------2.view one employee details----------------"<<endl;
            cout << "\n\n\n\t\t\t\t----------------3.Add employee----------------"<<endl;
            cout << "\n\n\n\t\t\t\t----------------4.delete employee----------------"<<endl;
            cout<<"\n\n\n\n\t\t*Enter the number of the section: ";
            cin>>x;
            switch (x)
            {
            case 1:
            {
               o1.viewStaff();
                break;
            }
            
            case 2:
            {
                o1.getOneEmployeeDetails();
                break;
            }
            
            case 3:
            {
                o1.addStaff();
                break;
            }
            case 4:
            {
               o1.deleteStaffMember();
                break;
            }
            default:
            {
                cout << "Invalid input";
                break;
            } //option to go back
            }
            ;
            break;
        }
        case 4:
        {
			exit(0);
        }
        }
        ;
        break;
    }
    }
	
    return 0;
}

