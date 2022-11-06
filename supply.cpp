#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "supply.h"

using namespace std;

void localshipment::setdata()
{
	cout<<"product unicode : ";
    cin>>productUnicode;
    cout << "product name:" << endl;
    cin >> productName;
    cout << "origin:" << endl;
    cin >> origin;
    //bool d1 = false, d2 = false;
	/*
    while (d1 == false)
    {
        //cin >> arrivalDate;
        cout << "Date of arrival:(dd-mm-yyyy)" << endl;
        validateDate(arrivalDate);
    }

    while (d2 == false)
    {

        //cin >> depatureDate;
        cout << "Date of departure:(dd-mm-yyyy)" << endl;
        validateDate(depatureDate);
    }
    */
    cout<<"arrival date : "<<endl;
	cin >> arrivalDate;
    cout << "Date of departure:" << endl;
    cin >> depatureDate;
    cout << "vehicle:" << endl;
    cin >> vehicle;
    cout<<"vehicle register number :"<<endl;
    cin>>vehicleRegNum;
    cout<<"quantity :"<<endl;
    cin>>quantity;
    status=0;
        
    // open file and save details
    fstream file;
  
    // opens an existing csv file or creates a new file.
    file.open("pendingSupply.csv", ios::out | ios::app);
   		
    // Insert the data to file
    file <<productUnicode<< ","<<productName<< ","<<quantity<< ","<<origin<<","<<vehicle<< ","<<vehicleRegNum<<","<<arrivalDate<<","<<depatureDate<<","<<status<<"\n";
    file.close();
}

void localshipment::showdata()
{
	cout << "product name:" << productName << endl;
    cout << "origin:" << origin << endl;
    cout << "Date of arrival:" << arrivalDate << endl;
    cout << "Date of departure:" << depatureDate << endl;
}

void Intershipment::setdata()
{
	cout<<"product unicode : ";
    cin>>productUnicode;
    cout << "product name:" << endl;
    cin >> productName;
    cout << "origin:" << endl;
    cin >> origin;
    //bool d1 = false, d2 = false;
	/*
    while (d1 == false)
    {
        //cin >> arrivalDate;
        cout << "Date of arrival:(dd-mm-yyyy)" << endl;
        validateDate(arrivalDate);
    }

    while (d2 == false)
    {

        //cin >> depatureDate;
        cout << "Date of departure:(dd-mm-yyyy)" << endl;
        validateDate(depatureDate);
    }
    */
    cout<<"arrival date : "<<endl;
	cin >> arrivalDate;
    cout << "Date of departure:" << endl;
    cin >> departureDate;
    cout << "ship number:" << endl;
    cin >> shipNum;
    cout<<"quantity :"<<endl;
    cin>>quantity;
    status=0;
        
    // open file and save details
    fstream file;
  
    // opens an existing csv file or creates a new file.
    file.open("pendingSupply.csv", ios::out | ios::app);
   		
    // Insert the data to file
    file <<productUnicode<< ","<<productName<< ","<<quantity<< ","<<origin<<","<<shipNum<<","<<arrivalDate<<","<<departureDate<<","<<status<<"\n";
    file.close();
	
}

void Intershipment::showdata()
{
	cout << "product name:" << productName << endl;
    cout << "origin:" << origin << endl;
    cout << "Date of arrival:" << arrivalDate << endl;
    cout << "Date of departure:" << departureDate << endl;
}



