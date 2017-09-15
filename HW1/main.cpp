#include "product.h"
#include "product.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <istream>

int main()
{
	string name;
	int sales;
	cout << "In main program" << endl;
	Product p1;

	cout << "Enter name: " << endl; 
	getline(cin, name);

	cout << "Enter sales: " << endl;
	cin>>sales;

	p1.setName(name);
	p1.setSales(sales);

	cout << p1.getName() << " " << p1.getSales() << "\n";
	cout<<"Press ENTER to quit\n";
	while (cin.get() != '\n')
		{}
	;

	return 0;
}
