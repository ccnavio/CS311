// product.h
// Carie Navio
// 6 Sep 2017
// 
// CS 311 Fall 2017
// Homework 1 

#ifndef FILE_PRODUCT_H_INCLUDED
#define FILE_PRODUCT_H_INCLUDED 

#include <ostream>
using std::ostream;
#include <string>

// Class Product - Class identification
// 
// Class Product
// Product names, number of sales

class Product {

// Product: ctors, dtors, assignements
public:
	// Default ctor
	// Sets name to empty string and number of sales to 0
	// Pre: None
	// Post: Empty string as name, zero sales
	Product()
	{
		setName("");
		setSales(0);
	}

	// Ctor from data
	// Sets names and sales to passed parameters
	// Pre : Sales >= 0
	//Post: Name and sales set to passed parameters
	Product(std::string name, int sales)
	{
		setName(name);
		setSales(sales);
	}

	// Use compiler generated verstions for the five 
	~Product() = default;
	Product(const Product & other) = default;
	Product(Product && other) = default;
	Product & operator=(const Product & other) = default;
	Product & operator=(Product && other) = default;

// General member functions
public:
	// getName
	// Pre: None
	// Post: Return is name of the product represented by *this
	std::string getName() const {
		return name_;
	}

	// getSales
	// Pre: None
	// Post: Return is number of the sales represented by *this
	int getSales() const {
		return sales_;
	}

	// setName
	// Pre: None
	// Post: Product name is set to passed string
	void setName(std::string new_name) {
		name_ = new_name;
	}

	// setSales
	// Pre: None
	// Post: Product sale is set to passed int
	void setSales(int new_sales) {
		sales_ = new_sales;
	}

// Public operators 
public:

	// op++ [pre]
	// Pre: None
	// Post: Product sales incremented by 1, state of *this returned
	Product & operator++()
	{
		++sales_;
		return *this;
	}
	// op++ [post]
	// Pre: None
	// Post: Product sales incremented by 1, former state of *this returned 
	Product operator++(int dummy)
	{
		Product save = *this;
		++*this;
		return save;
	}

	// op-- [pre]
	// Pre: None
	// Post: Product sales decremented by 1, state of *this returned
	// Must be greater than 0
	Product & operator--()
	{
		if (sales_ > 0)
			--sales_;
		return *this;
	}

	// op-- [post]
	// Pre: None
	// Post: Product sales decremented by 1, former state of *this returned 
	// Must bee greater than 0
	Product operator--(int dummy)
	{
		Product save = *this;
		--*this;
		return save;
	}

	// toString
	// Return string of Product data members
	// Pre: None
	// Post: Return is in string format
	// Defined in source file 
	std::string toString() const;

// Data members
private:
	std::string name_;
	int sales_;
};
// End of class Product

// op==(Product, Product)
// Pre: None
// Post: Return true if a==b
// (both names and sales are equal)
bool operator==(const Product & a, const Product & b);

// op!=(Product, Product)
// Pre: None
// Post: Return true if a != b
// (either the name of sales are not equal)
bool operator!=(const Product & a, const Product & b);

// op<<(ostream, Product)
// Pre: None
// Post: Output the given Product in the same form as toString
ostream & operator<<(ostream & out, const Product & p);

#endif //#ifndef FILE_PRODUCT_H_INCLUDED
