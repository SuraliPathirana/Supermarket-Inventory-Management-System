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

vector<string> productname;
vector<int> unicodevec;
vector<float> pricevec;
vector<float> quantityvec;
vector<string> unitprice;
//int Employee::employeeCount = 0;

void createProducts()
{
	int catogary;
	cout<<"enter the catogary number of the product you want to create: ";
	cin>>catogary;
	switch(catogary)
	{
		case 1: {	Produce temp;
					temp.getDetails();
					break;	}
		case 2: {	MeatAndSeafood temp;
					temp.getDetails();
					break;	}
		case 3: {	Grains temp;
					temp.getDetails();
					break;	}
		case 4: {	BakeryProducts temp;
					temp.getDetails();
					break;	}
		case 5: {	FrozenFoods temp;
					temp.getDetails();
					break;	}
		case 6: {	DiaryProducts temp;
					temp.getDetails();
					break;	}
		case 7: {	SnacksAndSweets temp;
					temp.getDetails();
					break;	}
		case 8: {	Beverages temp;
					temp.getDetails();
					break;	}
		case 9: {	HealthAndBeauty temp;
					temp.getDetails();
					break;	}
		case 10: {	CondimentsAndSpices temp;
					temp.getDetails();
					break;	}			
	}
	/*
	char choice;
	cout<<"\nDo you wish to create more products? if yes enter 'y' or 'Y' or if no enter 'n' or 'N' :";
	cin>>choice;
	if(choice=='y' || choice=='Y')
		createProducts();
	*/
}


//check whether the product is exist in the stock. return true if exist
bool checkProductAvailability(int uni)
{
	int count=0;
	// File pointer
    fstream file;
  
    // Open an existing record
    file.open("stock.csv", ios::in);
    
    string line, word;
    vector<string> row;
    
    // Traverse the file
    while (!file.eof()) {
  
        row.clear();
  
        getline(file, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
  
        int num1 = atoi(row[0].c_str()); //convert the string of unicode to a integer
        //int row_size = row.size();
  
        if (num1 == uni) 
		{
			count=1;
			//cout<<"product exist\n";
            return true;
    	}
	}
	if(count==0)
	{
		//cout<<"product doesnt exist\n";
		return false;
	}
		
}

//increase the quantity of a existing stock
void increaseStock(int uni,float increasedQuantity)
{
	int count=0;
	/*
	int uni, count=0;
	float increasedQuantity;
	cout<<"enter the unicode of the product you want to increase : ";
	cin>>uni;
	cout<<"enter the increased quantity : ";
    cin>>increasedQuantity;
    */
    int indexQuantity = 2; //quantity is at the second column index
    
    //if(checkProductAvailability(uni))
    
	// File pointer
   	fstream fin, fout;
   	// Open an existing record
    fin.open("stock.csv", ios::in);
    // Create a new file to store updated data
    fout.open("stocknew.csv", ios::out);
    
    string line, word;
    vector<string> row;
    
    // Traverse the file
    while (!fin.eof()) {
  
        row.clear();
  
        getline(fin, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
  
        int num1 = atoi(row[0].c_str()); //convert unicode number to an integer
        float num2 = atof(row[2].c_str()); //convert qauntity to an float and store
        
        
        int row_size = row.size();
  
        if (num1 == uni) {
            count = 1;
            stringstream convert;
  
            // sending a number as a stream into output string
            convert << (num2+increasedQuantity);
  
            // the str() converts number into string
            row[2] = convert.str();
  
            if (!fin.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
  
                    // write the updated data
                    // into a new file 'reportcardnew.csv'
                    // using fout
                    fout << row[i] << ",";
                }
  
                fout << row[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
  
                    // writing other existing records
                    // into the new file using fout.
                    fout << row[i] << ",";
                }
  
                // the last column data ends with a '\n'
                fout << row[row_size - 1] << "\n";
            }
        }
        if (fin.eof())
            break;
    }
    if (count == 0)
        cout << "Record not found\n";
  
    fin.close();
    fout.close();
  
    // removing the existing file
    remove("stock.csv");
  
    // renaming the updated file with the existing file name
    rename("stocknew.csv", "stock.csv");
    
}

//decrease the quantity of a existing stock
void decreaseStock(int uni,float quant)
{
	int count=0;
	
    int indexQuantity = 2; //quantity is at the second column index
    
	// File pointer
   	fstream fin1, fout1;
   	// Open an existing record
    fin1.open("stock.csv", ios::in);
    // Create a new file to store updated data
    fout1.open("stocknew.csv", ios::out);
    
    string line, word;
    vector<string> row;
    
    // Traverse the file
    while (!fin1.eof()) {
  
        row.clear();
  
        getline(fin1, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
  
        int num1 = atoi(row[0].c_str()); //convert unicode number to an integer
        float num2 = atof(row[2].c_str()); //convert qauntity to an float and store
        
        int row_size = row.size();
  
        if (num1 == uni) {
            count = 1;
            stringstream convert;
  
            // sending a number as a stream into output string
            convert << (num2-quant);
  
            // the str() converts number into string
            row[2] = convert.str();
  
            if (!fin1.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
  
                    // write the updated data
                    // into a new file 'reportcardnew.csv'
                    // using fout
                    fout1 << row[i] << ",";
                }
  
                fout1 << row[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin1.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
  
                    // writing other existing records
                    // into the new file using fout.
                    fout1 << row[i] << ",";
                }
  
                // the last column data ends with a '\n'
                fout1 << row[row_size - 1] << "\n";
            }
        }
        if (fin1.eof())
            break;
    }
    //if (count == 0)
    //    cout << "Record not found\n";
  
    fin1.close();
    fout1.close();
  
    // removing the existing file
    remove("stock.csv");
  
    // renaming the updated file with the existing file name
    rename("stocknew.csv", "stock.csv");
    
}




void Employee::getStaffDetails()
{
    cout<<"full name: ";
	cin>>name;
	cout<<"level : ";
	cin>>level;  //1-floorworker     2-cashier   3-manager    4-owner
	cout<<"joined date : ";
	cin>>joinedday;
	cout<<"joined month : ";
	cin>>joinedmonth;
	cout<<"joined year : ";
	cin>>joinedyear;
	cout<<"username : ";
	cin>>username;
	cout<<"password : ";
	cin>>password;
		
	// open file and save details
    fstream file1;
  
    // opens an existing csv file or creates a new file.
    file1.open("staff.csv", ios::out | ios::app);
    		
   	// Insert the data to file
    file1 <<name<< ","<<level<< ","<<joinedday<< ","<<joinedmonth<< ","<<joinedyear<< ","<<username<<","<<password<<"\n";
    file1.close();
    cout<<"\nemployeee successfully added to the staff\n ";
}

int Employee::getRoleNum(string usern,string psword)
{
	int count=0;
	// File pointer
    fstream file;
  
    // Open an existing record
    file.open("staff.csv", ios::in);
    
    string line, word;
    vector<string> row;
    
    // Traverse the file
    while (!file.eof()) {
  
        row.clear();
  
        getline(file, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
  
        //int num1 = atoi(row[0].c_str()); //convert the string of unicode to a integer
        int row_size = row.size();
  
        if (usern == row[5] && psword==row[6]) 
		{
			count=1;
			//cout<<"product exist\n";
			int roleNum= atoi(row[1].c_str()); 
            return roleNum;
    	}
	}
	
	if(count==0)
	{
		//cout<<"no staff member matching with entered details\n";
		return 0;
	}
	
}

void Floorworker::restockAvailableItems()
{
	// File pointer
    fstream file1;
  
    // Open an existing record
    file1.open("pendingSupply.csv", ios::in);
    
    string line, word;
    vector<string> row;
    
    // Traverse the file
    while (file1.peek()!=EOF) {
  
        row.clear();
  
        getline(file1, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
  
        int num1 = atoi(row[0].c_str()); //convert the string of unicode to a integer
        float num2 = atof(row[2].c_str()); //convert qauntity string to float
        int num3 = atoi(row[8].c_str()); //convert status string to an integer
        int row_size = row.size();
  
        if (checkProductAvailability(num1)==true && num3==0)
		{
			increaseStock(num1,num2);
			num3=1;
			cout<<"products in the pending list successfully added to the stock\n";
		}
		
		//else
		//	cout<<num1<<"product not available in the stock\n"; 
			
		if(file1.eof())
			break;
	}
	
	file1.close();
	
}

void Manager::viewStaff()
{
	string name1,username1,password1,level1,joinedday1,joinedmonth1,joinedyear1;
	
	ifstream file("staff.csv");
	while(file.peek()!=EOF)
	{
		getline(file,name1,',');
		getline(file,level1,',');
		getline(file,joinedday1,',');
		getline(file,joinedmonth1,',');
		getline(file,joinedyear1,',');
		getline(file,username1,',');
		getline(file,password1,'\n');
		
		cout<<"name = "<<name1;
		cout<<"\nlevel = "<<level1;
		cout<<"\njoinedday = "<<joinedday1;
		cout<<"\njoinedmonth = "<<joinedmonth1;
		cout<<"\njoinedyear = "<<joinedyear1;
		cout<<"\nusername = "<<username1;
		cout<<"\npassword = "<<password1<<"\n\n";
		
		if(file.eof())
			break;
	}
	
	file.close();
}

void Owner::deleteStaffMember()
{
	// Open FIle pointers
    fstream fin, fout;
  
    // Open the existing file
    fin.open("staff.csv", ios::in);
  
    // Create a new file to store the non-deleted data
    fout.open("staffnew.csv", ios::out);
  	
  	
  	int count=0;
  	string usname,usern;
  	
   
    string line, word;
    vector<string> row;
  
    // Get the roll number
    // to decide the data to be deleted
    cout << "Enter the username of the staff member you want to delete : ";
    cin >> usname;
  
    // Check if this record exists
    // If exists, leave it and
    // add all other data to the new file
    while (!fin.eof()) {
  
        row.clear();
        getline(fin, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
  
        int row_size = row.size();
        usern = row[5];
  
        // writing all records,
        // except the record to be deleted,
        // into the new file 'reportcardnew.csv'
        // using fout pointer
        if (usern != usname) {
            if (!fin.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else {
            count = 1;
        }
        if (fin.eof())
            break;
    }
    if (count == 1)
        cout << "Record deleted\n";
    else
        cout << "Record not found\n";
  
    // Close the pointers
    fin.close();
    fout.close();
  
    // removing the existing file
    remove("staff.csv");
  
    // renaming the new file with the existing file name
    rename("staffnew.csv", "staff.csv");
}


void Manager::restockNewItems()
{
	// File pointer
    fstream file1;
  
    // Open an existing record
    file1.open("pendingSupply.csv", ios::in);
    
    string line, word;
    vector<string> row;
    
    // Traverse the file
    while (!file1.eof()) {
  
        row.clear();
  
        getline(file1, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
  
        int num1 = atoi(row[0].c_str()); //convert the string of unicode to a integer
        string namestr = row[1];
        float num2 = atof(row[2].c_str()); //convert qauntity string to float
        int row_size = row.size();
        int num3 = atoi(row[row_size-1].c_str()); //convert status string to an integer
  
        if (checkProductAvailability(num1)==false && num3==0)
		{
			cout<<"unicode = "<<num1<<",name = "<<namestr<<",quantity = "<<num2<<", product is not avalable in the stock. therefore create new entry\n";
			createProducts();
			num3=1;
		}
		
	}
}

void Floorworker::addSupply()
{
	char choice;
	char choice2;
	cout<<"if you want to add local supply inventories, enter 'l' or 'L'. else enter 'i' or 'I' to add international supply inventories : ";
	cin>>choice;
	if(choice=='l' || choice=='L')
	{
		localshipment temp;
		temp.setdata();
		cout<<"\ndo you want to add more more supplies? if yes enter 'y' or 'Y', else enter 'n' 'N' : ";
		cin>>choice2;
		if(choice2=='y' || choice2=='Y')
			addSupply();
	}
	
	else if(choice=='i' || choice=='I')
	{
		Intershipment temp;
		temp.setdata();
		cout<<"\ndo you want to add more more supplies? if yes enter 'y' or 'Y', else enter 'n' 'N' : ";
		cin>>choice2;
		if(choice2=='y' || choice2=='Y')
			addSupply();
	}
}

void Cashier::createAndDisplayBill(float totalPrice, int n)
{
    int unicode;
    float quantity;
    cout << "enter the unicode of the product :";
    cin >> unicode;
    //int n;

    if (checkProductAvailability(unicode))
    {

        cout << "enter the quantity : ";
        cin >> quantity;
        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("stock.csv", ios::in);

        int unicodenum, count = 0;

        // Read the Data from the file
        // as String Vector
        vector<string> row;
        string line, word, temp;

        while (!fin.eof())
        {

            row.clear();

            // read an entire row and
            // store it in a string variable 'line'
            getline(fin, line);

            // used for breaking words
            stringstream s(line);

            // read every column data of a row and
            // store it in a string variable, 'word'
            while (getline(s, word, ','))
            {

                // add all the column data
                // of a row to a vector
                row.push_back(word);
            }

            unicodenum = atoi(row[0].c_str()); // convert unicode string to integer for comparision

            // Compare the roll number
            if (unicodenum == unicode)
            {
                n++;
                // Print the found data
                //count = 1;
                unicodevec.push_back(unicode);
                quantityvec.push_back(quantity);
                productname.push_back(row[1]);
                unitprice.push_back(row[3]);
                float price = atof(row[5].c_str()) * quantity; //convert finalPrice string to a float
                totalPrice += price;
                pricevec.push_back(price);
                //cout << row[0] << "\t" << row[1] << "\t" << quantity << "\t" << row[3] << "\t" << row[4] << "\t" << price << "\n";
                fin.close();
                decreaseStock(unicode, quantity);

                break;
            }
        }
        //if (count == 0)
        	//cout << "Record not found\n";
    }
    else
    	cout<<"record not found\n";
    	
    char choice;
    cout<<"do you want to bill more products? if yes enter 'y' or 'Y' or else enter 'n' or 'N' :";
    cin>>choice;
    if(choice=='y'  || choice=='Y')
    	createAndDisplayBill(totalPrice,n);
    	
    else if(choice=='n' || choice=='N')
    {
    	cout << "		****ABC SUPERMARKET****		\n"
            //"**receipt**\n"
            "unicode\t\tproduct\t\tquantity\t\tprice\t\ttotal"
         << endl;
    	//cout << "size=" << unicodevec.size();
    	for (int i = 0; i < n; i++)
    	{
        	cout << unicodevec[i] << "\t\t" << productname[i] << "\t\t" << quantityvec[i] << "\t\t" << unitprice[i] << "\t\t" << pricevec[i] << "\t\t" << endl;
    	}

    	cout << "\nfinal bill price = " << totalPrice;
    	
    	/*
    	cout<<"\n\n\n\n";
		cout<<"............Final Bill..........";
		cout<<endl<<endl;
		cout<<"unicode-productname-quantity-unitprice-price\n";
		for(int i=0;i<n;i++)
		{
			cout<<unicodevec[i]<<"-"<<productname[i]<<"-"<<quantityvec[i]<<"-"<<unitprice[i]<<"-"<<pricevec[i]<<"\n";
		}
		cout<<"\nTotal price = "<<totalPrice;
    	*/
	}	
}

void Owner::addStaff()
{
	Employee tempary;
	tempary.getStaffDetails();
	char choice;
	cout<<"do you want to add more staff members? if yes enter 'y' or 'Y' else enter 'n' or 'N' : ";
	cin>>choice;
	if(choice=='y' || choice=='Y')
		addStaff();
}

void Manager::getOneEmployeeDetails()
{
	string username;
	cout<<"enter the username of the employee you want to search : ";
	cin>>username;
    int count = 0;
    // File pointer
    fstream file;

    // Open an existing record
    file.open("staff.csv", ios::in);

    string line, word;
    vector<string> row;
    // Traverse the file
    while (!file.eof())
    {

        row.clear();

        getline(file, line);
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        // int num1 = atoi(row[0].c_str()); //convert the string of unicode to a integer
        //int row_size = row.size();

        if (row[5] == username)
        {
            count = 1;
            //cout<<"product exist\n";
            // return true;
            cout << "Name-" << row[0] << endl;
            cout << "position-" << row[1] << endl;
            cout << "joined date-" << row[2] << endl;
            cout << "joined month-" << row[3] << endl;
            cout << "joined year-" << row[4] << endl;
            cout << "username-" << row[5] << endl;
            cout << "passsword-" << row[6] << endl;
        }
    }
    if (count == 0)
    {
        cout << "Invalid credentials!" << endl;
    }
    file.close();
}


void Manager::removeProduct()
{
	// Open FIle pointers
    fstream fin, fout;
  
    // Open the existing file
    fin.open("stock.csv", ios::in);
  
    // Create a new file to store the non-deleted data
    fout.open("stocknew.csv", ios::out);
  	
  	
  	int count=0;
  	int uncode,uncode1;
  	
   
    string line, word;
    vector<string> row;
  
    // Get the roll number
    // to decide the data to be deleted
    cout << "Enter the unicode of the product you want to delete : ";
    cin >> uncode;
  
    // Check if this record exists
    // If exists, leave it and
    // add all other data to the new file
    while (!fin.eof()) {
  
        row.clear();
        getline(fin, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
  
        int row_size = row.size();
        uncode1 = atoi(row[0].c_str()); 
  
        // writing all records,
        // except the record to be deleted,
        // into the new file 'reportcardnew.csv'
        // using fout pointer
        if (uncode1 != uncode) {
            if (!fin.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else {
            count = 1;
        }
        if (fin.eof())
            break;
    }
    if (count == 1)
        cout << "Record deleted\n";
    else
        cout << "Record not found\n";
  
    // Close the pointers
    fin.close();
    fout.close();
  
    // removing the existing file
    remove("stock.csv");
  
    // renaming the new file with the existing file name
    rename("stocknew.csv", "stock.csv");
}

void Manager::createInitialStock()
{
	createProducts();
}

/*
void floorworker::createProducts()
{	
	int catogary;
	cout<<"enter the catogary number of the product you want to create: ";
	cin>>catogary;
	switch(catogary)
	{
		case 1: {	Produce temp;
					temp.getDetails();
					break;	}
		case 2: {	MeatAndSeafood temp;
					temp.getDetails();
					break;	}
		case 3: {	Grains temp;
					temp.getDetails();
					break;	}
		case 4: {	BakeryProducts temp;
					temp.getDetails();
					break;	}
		case 5: {	FrozenFoods temp;
					temp.getDetails();
					break;	}
		case 6: {	DiaryProducts temp;
					temp.getDetails();
					break;	}
		case 7: {	SnacksAndSweets temp;
					temp.getDetails();
					break;	}
		case 8: {	Beverages temp;
					temp.getDetails();
					break;	}
		case 9: {	HealthAndBeauty temp;
					temp.getDetails();
					break;	}
		case 10: {	CondimentsAndSpices temp;
					temp.getDetails();
					break;	}			
	}
	
	char choice;
	cout<<"\nDo you wish to create more products? if yes enter 'y' or 'Y' or if no enter 'n' or 'N' :";
	cin>>choice;
	if(choice=='y' || choice=='Y')
		createProducts();

}
*/












/*
void Employee::increaseStock()
{
    int uni, count = 0;
    float increasedQuantity;
    cout << "enter the unicode of the product you want to increase : ";
    cin >> uni;
    if (checkProductAvailability(uni))
    {

        int indexQuantity = 2; //quantity is at the second column index

        // File pointer
        fstream fin, fout;
        // Open an existing record
        fin.open("stock.csv", ios::in);
        // Create a new file to store updated data
        fout.open("stocknew.csv", ios::out);

        string line, word;
        vector<string> row;

        // Traverse the file
        while (!fin.eof())
        {

            row.clear();

            getline(fin, line);
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            int num1 = atoi(row[0].c_str()); //convert unicode number to an integer
            int row_size = row.size();

            if (num1 == uni)
            {
                count = 1;
                stringstream convert;
                float num2 = atof(row[2].c_str()); //convert qauntity to an float and store
                displayDetails(row);
                cout << "\n\nenter the quantity to be added: ";
                cin >> increasedQuantity;

                // sending a number as a stream into output string
                convert << (num2 + increasedQuantity);

                // the str() converts number into string
                row[2] = convert.str();

                if (!fin.eof())
                {
                    for (int i = 0; i < row_size - 1; i++)
                    {

                        // write the updated data
                        // into a new file 'reportcardnew.csv'
                        // using fout
                        fout << row[i] << ", ";
                    }

                    fout << row[row_size - 1] << "\n";
                }
                cout << "new total quantity-" << num2 + increasedQuantity << endl;
                cout << "**successfully updated**" << endl;
            }
            else
            {
                if (!fin.eof())
                {
                    for (int i = 0; i < row_size - 1; i++)
                    {

                        // writing other existing records
                        // into the new file using fout.
                        fout << row[i] << ", ";
                    }

                    // the last column data ends with a '\n'
                    fout << row[row_size - 1] << "\n";
                }
            }
            if (fin.eof())
                break;
        }
        if (count == 0)
            cout << "Record not found\n";

        fin.close();
        fout.close();

        // removing the existing file
        remove("stock.csv");

        // renaming the updated file with the existing file name
        rename("stocknew.csv", "stock.csv");
    }
}

void Cashier::printbill(float totalPrice, int n)
{
    cout << "		****ABC SUPERMARKET****		\n"
            //"**receipt**\n"
            "unicode\t\tproduct\t\tquantity\t\tprice\t\ttotal"
         << endl;
    //cout << "size=" << unicodevec.size();
    for (int i = 0; i < n; i++)
    {
        cout << unicodevec[i] << "\t\t" << productname[i] << "\t\t" << quantityvec[i] << "\t\t" << unitprice[i] << "\t\t" << pricevec[i] << "\t\t" << endl;
    }

    cout << "\nfinal bill price = " << totalPrice;
}
void Cashier::decreaseStock(int uni, float quant)
{
    int count = 0;

    int indexQuantity = 2; //quantity is at the second column index

    // File pointer
    fstream fin1, fout1;
    // Open an existing record
    fin1.open("stock.csv", ios::in);
    // Create a new file to store updated data
    fout1.open("stocknew.csv", ios::out);

    string line, word;
    vector<string> row;

    // Traverse the file
    while (!fin1.eof())
    {

        row.clear();

        getline(fin1, line);
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int num1 = atoi(row[0].c_str());   //convert unicode number to an integer
        float num2 = atof(row[2].c_str()); //convert qauntity to an float and store

        int row_size = row.size();

        if (num1 == uni)
        {
            count = 1;
            stringstream convert;

            // sending a number as a stream into output string
            convert << (num2 - quant);

            // the str() converts number into string
            row[2] = convert.str();

            if (!fin1.eof())
            {
                for (int i = 0; i < row_size - 1; i++)
                {

                    // write the updated data
                    // into a new file 'reportcardnew.csv'
                    // using fout
                    fout1 << row[i] << ", ";
                }

                fout1 << row[row_size - 1] << "\n";
            }
        }
        else
        {
            if (!fin1.eof())
            {
                for (int i = 0; i < row_size - 1; i++)
                {

                    // writing other existing records
                    // into the new file using fout.
                    fout1 << row[i] << ", ";
                }

                // the last column data ends with a '\n'
                fout1 << row[row_size - 1] << "\n";
            }
        }
        if (fin1.eof())
            break;
    }
    //if (count == 0)
    //    cout << "Record not found\n";

    fin1.close();
    fout1.close();

    // removing the existing file
    remove("stock.csv");

    // renaming the updated file with the existing file name
    rename("stocknew.csv", "stock.csv");
}

float Cashier::createAndDisplayBill(float totalPrice, int n)
{
    int unicode;
    float quantity;
    cout << "enter the unicode of the product :";
    cin >> unicode;
    //int n;

    if (checkProductAvailability(unicode))
    {

        cout << "enter the quantity : ";
        cin >> quantity;
        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("stock.csv", ios::in);

        int unicodenum, count = 0;

        // Read the Data from the file
        // as String Vector
        vector<string> row;
        string line, word, temp;

        while (!fin.eof())
        {

            row.clear();

            // read an entire row and
            // store it in a string variable 'line'
            getline(fin, line);

            // used for breaking words
            stringstream s(line);

            // read every column data of a row and
            // store it in a string variable, 'word'
            while (getline(s, word, ','))
            {

                // add all the column data
                // of a row to a vector
                row.push_back(word);
            }

            unicodenum = atoi(row[0].c_str()); // convert unicode string to integer for comparision

            // Compare the roll number
            if (unicodenum == unicode)
            {
                n++;
                // Print the found data
                //count = 1;
                unicodevec.push_back(unicode);
                quantityvec.push_back(quantity);
                productname.push_back(row[1]);
                unitprice.push_back(row[3]);
                float price = atof(row[5].c_str()) * quantity; //convert finalPrice string to a float
                totalPrice += price;
                pricevec.push_back(price);
                //cout << row[0] << "\t" << row[1] << "\t" << quantity << "\t" << row[3] << "\t" << row[4] << "\t" << price << "\n";
                decreaseStock(unicode, quantity);

                break;
            }
        }
        //if (count == 0)
        //	cout << "Record not found\n";
    }
    bool Manager ::checkEmployeeDetails(string username)
    {
        int count = 0;
        // File pointer
        fstream file;

        // Open an existing record
        file.open("employee.csv", ios::in);

        string line, word;
        vector<string> row;
        // Traverse the file
        while (!file.eof())
        {

            row.clear();

            getline(file, line);
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            // int num1 = atoi(row[0].c_str()); //convert the string of unicode to a integer
            //int row_size = row.size();

            if (row[3] == username)
            {
                count = 1;
                //cout<<"product exist\n";
                return true;
            }
        }
        if (count == 0)
        {
            //cout<<"product doesnt exist\n";
            return false;
            cout << "Invalid credentials!" << endl;
        }
    }

    void Manager::getEmployeeDetails(string username)
    {
        int count = 0;
        // File pointer
        fstream file;

        // Open an existing record
        file.open("employee.csv", ios::in);

        string line, word;
        vector<string> row;
        // Traverse the file
        while (!file.eof())
        {

            row.clear();

            getline(file, line);
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            // int num1 = atoi(row[0].c_str()); //convert the string of unicode to a integer
            //int row_size = row.size();

            if (row[3] == username)
            {
                count = 1;
                //cout<<"product exist\n";
                // return true;
                cout << "Name-" << row[0] << endl;
                cout << "position-" << row[1] << endl;
                cout << "joined date-" << row[2] << endl;
                cout << "employee number-" << row[3] << endl;
                cout << "username-" << row[3] << endl;
                cout << "passsword-" << row[4] << endl;
            }
        }
        if (count == 0)
        {
            //cout<<"product doesnt exist\n";
            return false;
            cout << "Invalid credentials!" << endl;
        }
    }

    void Manager::createProducts()
    {
        int catogary;
        cout << "enter the catogary number of the product you want to create: ";
        cin >> catogary;
        switch (catogary)
        {
        case 1:
        {
            Produce temp;
            temp.getDetails();
            break;
        }
        case 2:
        {
            MeatAndSeafood temp;
            temp.getDetails();
            break;
        }
        case 3:
        {
            Grains temp;
            temp.getDetails();
            break;
        }
        case 4:
        {
            BakeryProducts temp;
            temp.getDetails();
            break;
        }
        case 5:
        {
            FrozenFoods temp;
            temp.getDetails();
            break;
        }
        case 6:
        {
            DiaryProducts temp;
            temp.getDetails();
            break;
        }
        case 7:
        {
            SnacksAndSweets temp;
            temp.getDetails();
            break;
        }
        case 8:
        {
            Beverages temp;
            temp.getDetails();
            break;
        }
        case 9:
        {
            HealthAndBeauty temp;
            temp.getDetails();
            break;
        }
        case 10:
        {
            CondimentsAndSpices temp;
            temp.getDetails();
            break;
        }
        }

        char choice;
        cout << "\nDo you wish to create more products? if yes enter 'y' or 'Y' or if no enter 'n' or 'N' :";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
            createProducts();
    }

    void Owner::addStaff()
    {

        //create employees and store them in the csv file
    }
    void Owner::removeStaff()
    {
        //remove staff members from the csv file
    }
    
*/
