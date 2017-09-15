// product.cpp
// Carie Navio
// 6 Sep 2017
// 
// CS 311 Fall 2017
// Homework 1 

#include "product.h"
#include <string>
using std::string;
#include <ostream>
using std::ostream;
#include <sstream>
using std::ostringstream;

// Definition of member functions
//
// Product::toString()
// See header for documentation
string Product::toString() const 
{
	string name = getName();
	int sales = getSales();

	ostringstream ostr;
	ostr << name << " (sales: "<< sales <<")";
	return ostr.str();
}

// Global operators for class Product

// op == (Product, Product)
// See header for documentation
bool operator==(const Product & a, const Product & b){
	return (a.getName() == b.getName()) && (a.getSales() == b.getSales());
}

// op != (Product, Product)
// See header for documentation
bool operator!=(const Product & a, const Product & b){
	return !(a == b);
}

// op<<(ostream, Product)
// See header for documentation
ostream & operator<<(ostream & out, const Product & p){
	out << p.toString();
	return out;
}
