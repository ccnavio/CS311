// ksarray.h 
// Carie Navio
// 21 Sep 2017

// CS 311 Fall 2017
// Homework 2

#ifndef FILE_KSARRAY_H_INCLUDED
#define FILE_KSARRAY_H_INCLUDED

// VS won't compile without this
#define _SCL_SECURE_NO_WARNINGS 

#include <cstddef>
#include <algorithm>

template <typename ValueType>
class KSArray {
public:

	using size_type = std::size_t;
	using value_type = ValueType;
public:

	// Default ctor
	// Pre: None
	// Post: _ptr has size 10
	KSArray() 
		:_arrayptr(new value_type[10]), _size(10)
	{}

	// 1 parameter ctor
	// Pre: size >= 0
	// Post: _size set to passed value, points to array of size
	explicit KSArray(size_type size) 
		:_arrayptr(new value_type[size]), _size(size)
	{}

	// dtor
	// Pre: None
	// Post: Destroyed array references by _arrayptr
	~KSArray()
	{
		delete[] _arrayptr;
	}

	// 2 parameter ctor
	// Pre: size >= 0
	// Post: _size set to passed value, points to array of size
	KSArray(size_type size, value_type value) 
		:_arrayptr(new value_type[size], _size(size))
	{
		std::fill(begin(), end(), value);
	}

	// Copy ctor
	// Pre:: None
	// Post: Array elements are copied
	KSArray(const KSArray & other) 
		:_arrayptr(new value_type[other._size]), _size(other._size)
	{
		std::copy(other.begin(), other.end(), begin());
	}

	// More ctor
	// Pre: None
	// Post: 
	KSArray(KSArray && other) noexcept 
		:_arrayptr(other._arrayptr), _size(other._size)
	{
		other._arrayptr = new value_type[0];
		other._size = 0;
	}

	// Copy assignment 
	// Pre: None
	// Post: Array elements are copied
	KSArray & operator=(const KSArray & other)
	{
		KSArray copy(other);
		swapping(copy);
		return *this;
	}

	// Move assignment
	// Pre: None
	// Post: Sets value to size of other, points to what was array
	KSArray & operator=(KSArray && other) noexcept
	{
		swapping(other);
		return *this;
	}
private:
	void swapping(KSArray & other) noexcept
	{
		std::swap(_arrayptr, other._arrayptr);
		std::swap(_size, other._size);
	}

//**************************************************//
// General Public Operators
public:
	const value_type & operator[](size_type index) const
	{
		return _arrayptr[index];
	}

	value_type & operator[](size_type index)
	{
		return _arrayptr[index];
	}

//**************************************************//
// General Public Member Functions
public:
	
	// size
	// Pre: None
	// Post: Sets 
	size_type size() const
	{
		return _size;
	}

	// begin
	// Pre: None
	// Post: Pointer to beginning of array
	value_type * begin()
	{
		return _arrayptr;
	}

	const value_type * begin() const
	{
		return _arrayptr;
	}

	// end
	// Pre: None
	// Post: One element past the end of array
	value_type * end()
	{
		return _arrayptr + _size;
	}
	const value_type *end() const
	{
		return _arrayptr + _size;
	}


private:
	// Pointer to dynamic array
	value_type * _arrayptr;
	size_type _size;
};

//**************************************************//
// Global Operators 

// op==(Arr, Arr)
// Pre: None
// Post: Return true if a and b have same size and all contents
template <typename ValueType>
bool operator==(const KSArray<ValueType> & a, const KSArray<ValueType> & b)
{
	return (a.size() == b.size()) && std::equal(a.begin(), a.end(), b.begin());
}

// op!=(Arr, Arr)
// Pre: None
// Post: Return true if a and b do not have same size and all contents same
template <typename ValueType>
bool operator!=(const KSArray<ValueType> & a, const KSArray<ValueType> & b)
{
	return !(a == b);
}
// op<(Arr, Arr)
// Pre: None
// Post: Return true if a < b
template <typename ValueType>
bool operator<(const KSArray<ValueType> & a, const KSArray<ValueType> & b)
{
	for (std::size_t i = 0; i < b.size(); i++)
	{
		if (i >= a.size() || a[i] < b[i])
		{
			return true;
		}
		else if (b[i] < a[i])
		{
			return false;
		}
	}
	return false;
}

// op<=(Arr, Arr)
// Pre: None
// Post: Return true if a < b
template <typename ValueType>
bool operator<=(const KSArray<ValueType> & a, const KSArray<ValueType> & b)
{
	return !(a > b);
}

// op>(Arr, Arr)
// Pre: None
// Post: Return true if a > b
template <typename ValueType>
bool operator>(const KSArray<ValueType> & a, const KSArray<ValueType> & b)
{
	for (std::size_t i = 0; i < a.size(); i++)
	{
		if (i >= b.size() || a[i] > b[i])
		{
			return true;
		}
		else if (b[i] > a[i])
		{
			return false;
		}
	}
	return false;
}

// op>=(Arr, Arr)
// Pre: None
// Post: Return true if a >= b
template <typename ValueType>
bool operator>=(const KSArray<ValueType> & a, const KSArray<ValueType> & b)
{
	return !(a < b);
}

#endif
