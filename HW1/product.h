// product.h
// Carie Navio
// 6 Sep 2017

#ifndef PRODUCT_H
#define PRODUCT_H

#include <ostream>
using std::ostream;
#include <string>


class Product {

public:
	// Default ctor
	Product()
	{
		setName("");
		setSales(0);
	}

	Product(std::string name, int sales)
	{
		setName(name);
		setSales(sales);
	}

	~Product() = default;
	Product(const Product & other) = default;
	Product(Product && other) = default;
	Product & operator=(const Product & other) = default;
	Product & operator=(Product && other) = default;

public:

	std::string getName() const {
		return name_;
	}

	int getSales() const {
		return sales_;
	}

	void setName(std::string new_name) {
		name_ = new_name;
	}

	void setSales(int new_sales) {
		sales_ = new_sales;
	}

	std::string toString() const;

public:

	Product & operator++()
	{
		++sales_;
		return *this;
	}

	Product operator++(int dummy)
	{
		Product save = *this;
		++*this;
		return save;
	}

	Product & operator--()
	{
		if (sales_ > 0)
			--sales_;
		return *this;
	}

	Product operator--(int dummy)
	{
		Product save = *this;
		--*this;
		return save;
	}

private:
	std::string name_;
	int sales_;
};

bool operator==(const Product & a, const Product & b);
bool operator!=(const Product & a, const Product & b);

ostream & operator<<(ostream & out, const Product & p);

#endif
