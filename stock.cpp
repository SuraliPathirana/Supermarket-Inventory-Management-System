#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "stock.h"
#include "employee.h"


/*
Produce-1
meat and seafood - 2
grains - 3
Bakery products - 4
frozen foods - 5
diary products - 6
snacks and sweets - 7
beverages - 8
health and beuty - 9
condiments and spices - 10
*/

void Produce::showDetails()
{
    cout << unicode << "\t" << name << "\t" << quantity << "\t" << retail_price << "\t" << discount << "\t";
}
void Produce::getDetails()
{
    cout<<"enter the unicode of the product : ";
	cin>>unicode;
	cout<<"enter the name of the product : ";
	cin>>name;
	cout<<"enter the quantity in grams : ";
	cin>>quantity;
	cout<<"enter the retail price of 1 kg : ";
	cin>>retail_price;
	cout<<"enter the discount : ";
	cin>>discount;
	final_price = (retail_price-(retail_price*discount*0.01))/1000; //final price per 1 gram
			
	// open file and save details
    fstream file1;
 			 
    // opens an existing csv file or creates a new file.
    file1.open("stock.csv", ios::out | ios::app);
    		
    // Insert the data to file
    file1 <<unicode<< ","<<name<< ","<<quantity<< ","<<retail_price<< ","<<discount<< ","<<final_price<<"\n";
    file1.close();
}

void MeatAndSeafood::getDetails()
{
    cout<<"enter the unicode of the product : ";
	cin>>unicode;
	cout<<"enter the name of the product : ";
	cin>>name;
	cout<<"enter the quantity in grams : ";
	cin>>quantity;
	cout<<"enter the retail price of 1 kg : ";
	cin>>retail_price;
	cout<<"enter the discount : ";
	cin>>discount;
	final_price = (retail_price-(retail_price*discount*0.01))/1000; //final price per 1 gram
			
	// open file and save details
    fstream file2;
  
    // opens an existing csv file or creates a new file.
    file2.open("stock.csv", ios::out | ios::app);
    		
    // Insert the data to file
    file2 <<unicode<< ","<<name<< ","<<quantity<< ","<<retail_price<< ","<<discount<< ","<<final_price<<"\n";
    file2.close();
}
void MeatAndSeafood::showDetails()
{
    cout << unicode << "\t" << name << "\t" << quantity << "\t" << retail_price << "\t" << discount << "\t";
}

void Grains::showDetails()
{
    cout << unicode << "\t" << name << "\t" << brand << "\t" << local_imported << "\t" << quantity << "\t" << retail_price << "\t" << discount << "\t";
}
void Grains::getDetails()
{
    cout<<"enter the unicode of the product : ";
	cin>>unicode;
	cout<<"enter the name of the product : ";
	cin>>name;
	cout<<"enter the quantity in grams : ";
	cin>>quantity;
	cout<<"enter the retail price of 1 kg : ";
	cin>>retail_price;
	cout<<"enter the discount : ";
	cin>>discount;
	cout<<"enter the brand : ";
	cin>>brand;
	cout<<"enter whether local or imported :";
	cin>>local_imported;
	final_price = (retail_price-(retail_price*discount*0.01))/1000; //final price per 1 gram
			
	// open file and save details
    fstream file3;
  
    // opens an existing csv file or creates a new file.
    file3.open("stock.csv", ios::out | ios::app);
    		
    // Insert the data to file
    file3 <<unicode<< ","<<name<< ","<<quantity<< ","<<retail_price<< ","<<discount<< ","<<final_price<<","<<brand<< ","<<local_imported<<"\n";
    file3.close();
}

void BakeryProducts::getDetails()
{
    cout<<"enter the unicode of the product : ";
	cin>>unicode;
	cout<<"enter the name of the product : ";
	cin>>name;
	cout<<"enter the no of items : ";
	cin>>quantity;
	cout<<"enter the retail price of one item : ";
	cin>>retail_price;
	cout<<"enter the discount : ";
	cin>>discount;
	cout<<"enter the brand : ";
	cin>>brand;
	cout<<"enter whether local or imported :";
	cin>>local_imported;
	final_price = retail_price-(retail_price*discount*0.01); //final price per one item
			
	// open file and save details
    fstream file4;
  
    // opens an existing csv file or creates a new file.
    file4.open("stock.csv", ios::out | ios::app);
    		
    // Insert the data to file
    file4 <<unicode<< ","<<name<< ","<<quantity<< ","<<retail_price<< ","<<discount<< ","<<final_price<<","<<brand<< ","<<local_imported<<"\n";
    file4.close();
}
void BakeryProducts::showDetails()
{
    cout << unicode << "\t" << name << "\t" << brand << "\t" << local_imported << "\t" << quantity << "\t" << retail_price << "\t" << discount << "\t";
}

void FrozenFoods::showDetails()
{
    cout << unicode << "\t" << name << "\t" << brand << "\t" << local_imported << "\t" << quantity << "\t" << retail_price << "\t" << discount << "\t";
}
void FrozenFoods::getDetails()
{
    cout<<"enter the unicode of the product : ";
	cin>>unicode;
	cout<<"enter the name of the product : ";
	cin>>name;
	cout<<"enter the no of items : ";
	cin>>quantity;
	cout<<"enter the retail price of one item : ";
	cin>>retail_price;
	cout<<"enter the discount : ";
	cin>>discount;
	cout<<"enter the brand : ";
	cin>>brand;
	cout<<"enter whether local or imported :";
	cin>>local_imported;
	final_price = retail_price-(retail_price*discount*0.01);
			
	// open file and save details
    fstream file5;
  
    // opens an existing csv file or creates a new file.
    file5.open("stock.csv", ios::out | ios::app);
    		
    // Insert the data to file
    file5 <<unicode<< ","<<name<< ","<<quantity<< ","<<retail_price<< ","<<discount<< ","<<final_price<<","<<brand<< ","<<local_imported<<"\n";
    file5.close();
}

void DiaryProducts::showDetails()
{
    cout << unicode << "\t" << name << "\t" << brand << "\t" << local_imported << "\t" << quantity << "\t" << retail_price << "\t" << discount << "\t";
}
void DiaryProducts::getDetails()
{
    cout<<"enter the unicode of the product : ";
	cin>>unicode;
	cout<<"enter the name of the product : ";
	cin>>name;
	cout<<"enter the no of items : ";
	cin>>quantity;
	cout<<"enter the retail price of one item : ";
	cin>>retail_price;
	cout<<"enter the discount : ";
	cin>>discount;
	cout<<"enter the brand : ";
	cin>>brand;
	cout<<"enter whether local or imported :";
	cin>>local_imported;
	final_price = retail_price-(retail_price*discount*0.01);
			
	// open file and save details
    fstream file6;
  
    // opens an existing csv file or creates a new file.
    file6.open("stock.csv", ios::out | ios::app);
    		
    // Insert the data to file
    file6 <<unicode<< ","<<name<< ","<<quantity<< ","<<retail_price<< ","<<discount<< ","<<final_price<<","<<brand<< ","<<local_imported<<"\n";
    file6.close();
}

void SnacksAndSweets::getDetails()
{
    cout<<"enter the unicode of the product : ";
	cin>>unicode;
	cout<<"enter the name of the product : ";
	cin>>name;
	cout<<"enter the no of items : ";
	cin>>quantity;
	cout<<"enter the retail price of one item : ";
	cin>>retail_price;
	cout<<"enter the discount : ";
	cin>>discount;
	cout<<"enter the brand : ";
	cin>>brand;
	cout<<"enter whether local or imported :";
	cin>>local_imported;
	final_price = retail_price-(retail_price*discount*0.01);
			
	// open file and save details
    fstream file7;
  
   	// opens an existing csv file or creates a new file.
    file7.open("stock.csv", ios::out | ios::app);
    		
    // Insert the data to file
    file7 <<unicode<< ","<<name<< ","<<quantity<< ","<<retail_price<< ","<<discount<< ","<<final_price<<","<<brand<< ","<<local_imported<<"\n";
    file7.close();
}
void SnacksAndSweets::showDetails()
{
    cout << unicode << "\t" << name << "\t" << brand << "\t" << local_imported << "\t" << quantity << "\t" << retail_price << "\t" << discount << "\t";
}
void Beverages::getDetails()
{
    cout<<"enter the unicode of the product : ";
	cin>>unicode;
	cout<<"enter the name of the product : ";
	cin>>name;
	cout<<"enter the no of items : ";
	cin>>quantity;
	cout<<"enter the retail price of one item : ";
	cin>>retail_price;
	cout<<"enter the discount : ";
	cin>>discount;
	cout<<"enter the brand : ";
	cin>>brand;
	cout<<"enter whether local or imported :";
	cin>>local_imported;
	final_price = retail_price-(retail_price*discount*0.01);
			
	// open file and save details
    fstream file8;
  
    // opens an existing csv file or creates a new file.
    file8.open("stock.csv", ios::out | ios::app);
    		
    // Insert the data to file
    file8 <<unicode<< ","<<name<< ","<<quantity<< ","<<retail_price<< ","<<discount<< ","<<final_price<<","<<brand<< ","<<local_imported<<"\n";
    file8.close();
}
void Beverages::showDetails()
{
    cout << unicode << "\t" << name << "\t" << brand << "\t" << local_imported << "\t" << quantity << "\t" << retail_price << "\t" << discount << "\t";
}
void HealthAndBeauty::getDetails()
{
    cout<<"enter the unicode of the product : ";
	cin>>unicode;
	cout<<"enter the name of the product : ";
	cin>>name;
	cout<<"enter the no of items : ";
	cin>>quantity;
	cout<<"enter the retail price of one item : ";
	cin>>retail_price;
	cout<<"enter the discount : ";
	cin>>discount;
	cout<<"enter the brand : ";
	cin>>brand;
	cout<<"enter whether local or imported :";
	cin>>local_imported;
	final_price = retail_price-(retail_price*discount*0.01);
			
	// open file and save details
    fstream file9;
  
    // opens an existing csv file or creates a new file.
    file9.open("stock.csv", ios::out | ios::app);
    		
    // Insert the data to file
    file9 <<unicode<< ","<<name<< ","<<quantity<< ","<<retail_price<< ","<<discount<< ","<<final_price<<","<<brand<< ","<<local_imported<<"\n";
    file9.close();
}
void HealthAndBeauty::showDetails()
{
    cout << unicode << "\t" << name << "\t" << brand << "\t" << local_imported << "\t" << quantity << "\t" << retail_price << "\t" << discount << "\t";
}
void CondimentsAndSpices::getDetails()
{
    cout<<"enter the unicode of the product : ";
	cin>>unicode;
	cout<<"enter the name of the product : ";
	cin>>name;
	cout<<"enter the no of items : ";
	cin>>quantity;
	cout<<"enter the retail price of one item : ";
	cin>>retail_price;
	cout<<"enter the discount : ";
	cin>>discount;
	cout<<"enter the brand : ";
	cin>>brand;
	cout<<"enter whether local or imported :";
	cin>>local_imported;
	final_price = retail_price-(retail_price*discount*0.01);
			
	// open file and save details
    fstream file10;
  
    // opens an existing csv file or creates a new file.
    file10.open("stock.csv", ios::out | ios::app);
    		
    // Insert the data to file
    file10 <<unicode<< ","<<name<< ","<<quantity<< ","<<retail_price<< ","<<discount<< ","<<final_price<<","<<brand<< ","<<local_imported<<"\n";
    file10.close();
}
void CondimentsAndSpices::showDetails()
{
    cout << unicode << "\t" << name << "\t" << brand << "\t" << local_imported << "\t" << quantity << "\t" << retail_price << "\t" << discount << "\t";
}
