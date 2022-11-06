#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;


class localshipment
{

private:
    string productName, origin, vehicle,vehicleRegNum;
    string arrivalDate, depatureDate;
    int productUnicode;
    float quantity;
    int status;

public:
    void setdata();
    void showdata();
    /*
    bool validateDate(int *arr)
    {
        int temp;
        cout << "inside loop" << endl;
        for (int i = 0; i < 10; i++)
        {
            if (i != 2 && i != 5)
            {
                cin >> arr[i];
                cout << "i= " << endl;
            }
            else
            {
                cin >> temp;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (i != 2 && i != 5)
                cout << arr[i];
        }
        //for(int i = 0; i < 2; i++)

        for (int i = 0; i < 10; i++)
        {
            //cout<<(int(d[0]) * 10 + int(d[1]))<<endl;
            if (arr[0] * 10 + arr[1] > 31) //check the date
            {
                cout << "invalid input 1.Please enter the date again" << endl;
                return 0;
            }
            if (arr[3] == 0 && arr[4] == 2)
            {
                if (arr[0] * 10 + arr[1] > 29) //check date for february
                {
                    cout << "invalid input 2.Please enter the date again" << endl;
                    return 0;
                }
            }
            if (arr[3] * 10 + arr[4] > 12) //check the month
            {
                cout << "invalid input 3.Please enter the date again" << endl;
                return 0;
            };
        }
        return 1;
    }
    */
    
};

class Intershipment
{
private:
    int productUnicode;
    float quantity;
    string origin, productName,arrivalDate, departureDate;
    int shipNum;
    bool status;
public:
	void setdata();
    void showdata();
    /*
    bool validateDate(int *arr)
    {
        int temp;
        cout << "inside loop" << endl;
        for (int i = 0; i < 10; i++)
        {
            if (i != 2 && i != 5)
            {
                cin >> arr[i];
                cout << "i= " << endl;
            }
            else
            {
                cin >> temp;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (i != 2 && i != 5)
                cout << arr[i];
        }
        //for(int i = 0; i < 2; i++)

        for (int i = 0; i < 10; i++)
        {
            //cout<<(int(d[0]) * 10 + int(d[1]))<<endl;
            if (arr[0] * 10 + arr[1] > 31) //check the date
            {
                cout << "invalid input 1.Please enter the date again" << endl;
                return 0;
            }
            if (arr[3] == 0 && arr[4] == 2)
            {
                if (arr[0] * 10 + arr[1] > 29) //check date for february
                {
                    cout << "invalid input 2.Please enter the date again" << endl;
                    return 0;
                }
            }
            if (arr[3] * 10 + arr[4] > 12) //check the month
            {
                cout << "invalid input 3.Please enter the date again" << endl;
                return 0;
            };
        }
        return 1;
    }
    */
};
