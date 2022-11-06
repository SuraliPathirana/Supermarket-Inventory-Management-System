#include <iostream>

using namespace std;
/*
class Item{
	public:
		virtual void getDetails()=0;
};
*/
class Produce{
	public:
		int unicode;
		string name;
		float quantity,retail_price,discount,final_price;
		void getDetails();
		void showDetails();
};

class MeatAndSeafood{
	public:
		int unicode;
		string name;
		float quantity,retail_price,discount,final_price;
		void getDetails();
		void showDetails();
};

class Grains{
	public:
		int unicode;
		string name;
		float quantity,retail_price,discount,final_price;
		string brand,local_imported;
		void getDetails();
		void showDetails();
};

class BakeryProducts{
	public:
		int unicode,quantity;
		string name;
		float retail_price,discount,final_price;
		string brand,local_imported;
		void getDetails();
		void showDetails();
};

class FrozenFoods{
	public:
		int unicode,quantity;
		string name;
		float retail_price,discount,final_price;
		string brand,local_imported;
		void getDetails();
		void showDetails();
};

class DiaryProducts{
	public:
		int unicode,quantity;
		string name;
		float retail_price,discount,final_price;
		string brand,local_imported;
		void getDetails();
		void showDetails();
};

class SnacksAndSweets{
	public:
		int unicode,quantity;
		string name;
		float retail_price,discount,final_price;
		string brand,local_imported;
		void getDetails();
		void showDetails();
};

class Beverages{
	public:
		int unicode,quantity;
		string name;
		float retail_price,discount,final_price;
		string brand,local_imported;
		void getDetails();
		void showDetails();
};

class HealthAndBeauty{
	public:
		int unicode,quantity;
		string name;
		float retail_price,discount,final_price;
		string brand,local_imported;
		void getDetails();
		void showDetails();
};

class CondimentsAndSpices{
	public:
		int unicode,quantity;
		string name;
		float retail_price,discount,final_price;
		string brand,local_imported;
		void getDetails();
		void showDetails();
};

