// product.cpp
// Carie Navio
// 6 Sep 2017

#include "product.h"
#include <string>
using std::string;
#include <ostream>
using std::ostream;
#include <sstream>
using std::ostringstream;

string Product::toString() const {
	string name = getName();
	int sales = getSales();

	ostringstream ostr;
	ostr << name << "(sales: "<< sales <<")";
	return ostr.str();
}

bool operator==(const Product & a, const Product & b){
	return (a.getName() == b.getName()) && (a.getSales() == b.getSales());
}

bool operator!=(const Product & a, const Product & b){
	return !(a == b);
}

ostream & operator<<(ostream & out, const Product & p){
	out << p.toString();
	return out;
}
