#include<iostream>
#include<fstream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

class shopping{
	private:
		int productCode;
		int quantity;
		float price;
		float discount;
		string productName;
		
	public:
		void menu()
		{
			m:
			int choice;
			string email;
			string password;
			
			cout << "\n\n\t\t\t\t----------------------------------------------------------\n" << endl;
			cout << "\t\t\t\t               SuperMarket Main Menu                      \n" << endl;
			cout << "\t\t\t\t----------------------------------------------------------\n" << endl;
			cout << "\t\t\t\t |           1.  Administrator          |" << endl;
			cout << "\t\t\t\t |                                      |" << endl;
			cout << "\t\t\t\t |           2.  Buyer                  |" << endl;
			cout << "\t\t\t\t |                                      |" << endl;
			cout << "\t\t\t\t |           3.  Exit                   |" << endl;
			cout << "\t\t\t\t |                                      |" << endl;
			
			cout << "\n\t            Please Select !   ";
			cin >> choice;
			
			switch(choice)
			{
				case 1:
				{
					cout << "\n\t\t\t\t   Please Login   " << endl;
					cout << "\t\t   Enter Email  :  ";
					cin >> email;
					cout << "\t\t   Enter Password  :  ";
					cin >> password;
					
					if(email == "neeraj@gmail.com" && password == "neeraj@123")
					{
						administrator();
					}
					else{
						cout << "\n\n\t\t  Invalid Credentials !!" << endl;
					}
					break;
				}
				case 2:
				{
					buyer();
					break;
				}
				case 3:
				{
					exit(0);	
					break;
				}
				
				default :
				{
					cout << "\n\t\t Please Select From The Given Options" << endl;
					break;
				}	
			}
			goto m;
		}
		
		// Administrator
		void administrator()
		{
			m:
			int choice;
			cout << "\n\n\n\t\t\t |       Administrator MENU       |\n" << endl;
			cout << "\t\t\t |  ---- 1. Add the Product  -----  |" << endl;
			cout << "\t\t\t |  ---- 2. Modify the Product ---  |" << endl;
			cout << "\t\t\t |  ---- 3. Delete the Product ---  | " << endl;
			cout << "\t\t\t |  ---- 4. Back to Main Menu  ---  |" << endl;
			cout << "\n\n\t\t  Please Enter Your Choice  :  ";
			cin >> choice;
			
			switch(choice)
			{
				case 1:
				{
					add();
					break;
				}
				case 2:
				{
					edit();
					break;
				}
				case 3:
				{
					rem();
					break;
				}
				case 4:
				{
					menu();
					break;
				}
				default:
				{
					cout << "\n\n\t\t Invalid Choice !!" << endl;
				}
			}
			goto m;
		}
		
		void buyer()
		{
			m:
			int choice;
			cout << "\n\n\t\t      Buyer" << endl;
			cout << "\t\t --------------------\n" << endl;
			cout << "\t\t   1. Buy Product" << endl;
			cout << "\t\t   2. Go Back" << endl;
			cout << "\t\t   3. Exit" << endl;
			cout << "\n\t\t  Enter your Choice : ";
			cin >> choice;
			
			switch(choice)
			{
				case 1:
				{
					receipt();
					exit(0);
					break;
				}
				case 2: 
				{
					menu();
					break;
				}
				case 3:
				{
					exit(0);	
					break;
				}
				default:
				{
					cout << "\n\n\t\t Invalid Choice !!" << endl;
				}
			}
			goto m;
		}
		void add();
		void edit();
		void list();
		void rem();
		void receipt();
};

// file handing part
void shopping :: add()
{
	m:
	fstream data;
	int c;
	int token = 0;
	int q;
	float p;
	float d;
	string n;
	
	cout << "\n\n\t\t\t |   Add New Product   |\n" << endl;
	cout << "\t\t Product Code : ";
	cin >> productCode;
	cout << "\n\t\t Name of the Product : ";
	cin >> productName;
	cout << "\n\t\t Quantity of Product : ";
	cin >> quantity;
	cout << "\n\t\t Price on product : ";
	cin >> price;
	cout << "\n\t\t Discount on product : ";
	cin >> discount;
	
	// ios::in  ---> for opening the file in reading mode;
	// ios::out  ---> for opening the file in writing mode;
	data.open("database.txt", ios::in);
	
	if(!data)
	{
		data.open("database.txt", ios::app| ios::out);  // ios::app --> for append mode
		data << " " << productCode << " " << productName << " " << quantity << " "<< price << " " << discount << endl;
		data.close();
	}
	else
	{
		data >> c >> n >> q >> p >> d;
		while(!data.eof())  // for checking the duplicacy of product 
		{
			if(c == productCode)
			{
				token++;
			}
			data >> c >> n >> q >> p >> d;
		}
		data.close();
	
		if(token == 1){
			cout << "\n\n\t\t Addition of Duplicate Product Id is Not Allowed, Please Change !!" << endl; //aavda kam
			goto m;
		}
		else{
			data.open("database.txt", ios::app|ios::out);
			data << " " << productCode << " " << productName << " " << quantity << " " << price << " " << discount << endl;
			data.close();
		}
	}
	cout << "\n\n\t\t Record Inserted !!" << endl;
	list();
}

void shopping :: edit()
{
	m:
	fstream data, data1, data2;
	int pkey;
	int token = 0;
	int c1, q1, c,q;
	float p1, d1, p,d;
	string n1,n;
	
	cout << "\n\n\t\t |   Modify The Record   |\n" << endl;
	list();
	cout << "\n\n\t\t  Product Code present already in database : ";
	cin >> pkey;
	
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout << "\n\n\t\t File Doesn't Exist ..." << endl;
	}
	else{
		data1.open("database1.txt", ios::app| ios::out);
		data>>productCode>>productName>>quantity>>price>>discount;
		
		while(!data.eof())
		{
			if(pkey == productCode)
			{
				cout << "\n\t\t  Product New Code : ";
				cin >> c1;
				cout << "\n\t\t  Name of The Product : ";
				cin >> n1;
				cout << "\n\t\t  Quantity : ";
				cin >> q1;
				cout << "\n\t\t  Price : ";
				cin >> p1;
				cout << "\n\t\t  Discount : ";
				cin >> d1;
				
				data2.open("database.txt", ios::in);
				data2 >> c >> n >> q >> p >> d;
				while(!data2.eof())  // for checking the duplicacy of product 
				{
					if(c == c1)
					{
						token++;
					}
					data2 >> c >> n >> q >> p >> d;
				}
				data2.close();
				if(token == 1){
					cout << "\n\n\t\t Duplicate Product Id !!" << endl; //aavda kam
					data1.close();
					remove("database1.txt");
					goto m;
				}
				else{
					data1 <<" " << c1 << " " << n1 << " " << q1 << " "<< p1 << " " << d1 << endl;
					cout << "\n\n\t\t  Record Edited !!" << endl;
					token++;
				}
			}
			else{
				data1 << " " << productCode << " " << productName << " " << quantity << " "<< price << " " << discount << endl;
				
			}
			data >> productCode >> productName >> quantity >> price >> discount;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt", "database.txt");
		
		if(token == 0)
		{
			cout << "\n\n\t\t Record Not Found, Sorry ... " << endl;
		}
	}
	list();
}

void shopping :: rem()
{
	fstream data, data1;
	int pkey, token = 0;
	cout << "\n\n\t\t |   Delete Product   |" << endl;
	list();
	cout << "\n\n\t\t  Enter the Product code : ";
	cin >> pkey;
	
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout << "\n\n\t\t File Doesn't Exists ..." << endl;
	}
	else{
		data1.open("database1.txt", ios::app | ios::out);
		data >> productCode >> productName >> quantity >> price >> discount;
		while(!data.eof())
		{
			if(productCode == pkey)
			{
				cout << "\n\n\t\t  Product Deleted Successfully " << endl;
				token++;
			}
			else{
				data1 << " " << productCode << " " << productName << " " << quantity << " " << price << " " << discount << endl;
			}
			data >> productCode >> productName >>quantity >> price >> discount;
		}
		data1.close();
		data.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");
		
		if(token == 0)
		{
			cout << "\n\n\t\t\t Record Not Found" << endl;
		}
	}
	list();
}

void shopping :: list()
{
	fstream data;
	data.open("database.txt", ios::in);
	cout << "\n\t\t --------------------------------------------------------------------" << endl;
	cout << "\t\t ProductNo. \t\t Product Name\t\tQuantity\tPrice" << endl;
	cout << "\t\t --------------------------------------------------------------------" << endl;
	
	data >> productCode >> productName >> quantity >> price >> discount;
	
	while(!data.eof())
	{
		if(productName.size() > 12)
			cout << " \t\t  " << productCode << "\t\t\t " << productName << " \t " << quantity << " \t\t " << price << endl;
		else if(productName.size() > 8)
			cout << " \t\t  " << productCode << "\t\t\t " << productName << "\t\t " << quantity << " \t\t " << price << endl;
		else
			cout << " \t\t  " << productCode << "\t\t\t " << productName << "       \t\t " << quantity << " \t\t " << price << endl;				
		data >> productCode >> productName >> quantity >> price >> discount;
	}
	cout << "\t\t --------------------------------------------------------------------" << endl;
	data.close();
}

void shopping :: receipt()
{
	n:
	int count = 0;
	fstream data;
	int codes[100];
	int quantities[100];
	string choice;
	int c = 0, q = 0;
	float amount = 0, discount = 0;
	float total = 0;
	
	cout << "\n\n\t\t\t |****************   MAIN MENU   *****************|" << endl;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout << "\n\t\t  Empty Database" << endl;	
	}
	else{
		data.close();
		list();
		
		cout << "\n\n\t\t\t  ***********************************************\n" << endl;
		cout << "\t\t\t            Please Place the Order              " << endl;
		cout << "\n\t\t\t  ***********************************************\n" << endl;
		
		do
		{
			m:
			cout << "\n\t\t Enter Product Code : ";
			cin >> codes[c];
			cout << "\n\t\t Enter the Product Quantity : ";
			cin >> quantities[c];
			
			for(int i = 0; i < c; i++)
			{
				if(codes[c] == codes[i])
				{
					cout << "\n\n\t\t    Duplicate Product Please try Again .. " << endl;
					goto m;
				}
			}
			c++;
			cout << "\n\t\t Do you Want to Buy Another Product or Not ? If yes press 'y'or 'Y' else 'any Key' : ";
			cin >> choice;
		}
		while(choice == "y" || choice == "Y");
		
		cout << "\n\n\t\t *******************************  Important  ******************************** " << endl;		
		for(int i = 0; i < c; i++)
		{
			data.open("database.txt", ios::in);
			data >> productCode >> productName >> quantity >> price >> discount;
			while(!data.eof())
			{
				if(productCode == codes[i])
				{
					p:
					if(quantity < quantities[i])
					{
						char dec;
						cout << "\n\n\t\t You order More Quantity than available for product : " << productName << endl;
						cout << "\t\t Maximum Quantity that you can Order upto : " << quantity << endl;
						cout << "\t\t Update the quantity, if you don't want to buy just enter '0' :  ";
						cin >> quantities[i];
						goto p;
					}
				}
				data >> productCode >> productName >> quantity >> price >> discount;
			}
			data.close();
		}
		
		cout << "\n\n\t\t --------------------------------------  RECEIPT  -------------------------------------------- " << endl;
		cout << "\t\t ProductNo. \t\t Product Name\t\tQuantity\tTotal Price\t Amount with Discount" << endl;
		cout << "\t\t ---------------------------------------------------------------------------------------------" << endl;
		for(int i = 0; i < c; i++)
		{
			data.open("database.txt", ios::in);
			data >> productCode >> productName >> quantity >> price >> discount;
			while(!data.eof())
			{
				if(productCode == codes[i])
				{
					if(quantities[i] != 0) count++;
					amount = price * quantities[i];
					discount = amount - (amount*(discount/100));
					total = total + discount;
					if(productName.size() > 12)
						cout << " \t\t  " << productCode << "\t\t\t " << productName << " \t " << quantities[i] << " \t\t " << amount << "\t\t " << discount << endl;
					else if(productName.size() > 8)
						cout << " \t\t  " << productCode << "\t\t\t " << productName << "\t\t " << quantities[i] << " \t\t " << amount << "\t\t " << discount << endl;
					else
						cout << " \t\t  " << productCode << "\t\t\t " << productName << "       \t\t " << quantities[i] << " \t\t " << amount << "\t\t " << discount << endl;
				}
				data >> productCode >> productName >> quantity >> price >> discount;
			}
			data.close();
		}
	}
	cout << "\n\t\t ---------------------------------------------------------------------------------------------" << endl;
	cout << "\t\tTotal Amount : " << total << endl;
	cout << "\t\tTotal Item Purschased : " << count << endl;
}

int main()
{
	shopping s;
	s.menu();
}
