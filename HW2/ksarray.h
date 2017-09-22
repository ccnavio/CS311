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

//**************************************************//
// class KSArray - Class definition
//**************************************************//

// class KSArray
// pointer to start of array, size of array
// Invariants:
//		_arraypte points to array of int allocated with new[], owned by *this
//		_size >= 0
		
// Requirements on Types:
//		ValueType must be move-constructible and move-assignable
//		ValueType must have binary operators
template <typename ValueType>
class KSArray {

//**************************************************//
// KSArray: Types
//**************************************************//
public:
	// size_type: unsigned type for size of array
	// value_type: type of item in this container
	using size_type = std::size_t;
	using value_type = ValueType;

//**************************************************//
// KSArray: Ctors, dtor, op=
//**************************************************//
public:

	// Default ctor
	// Pre: None
	// Post: _arrayptr points to array of size 10
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
	// Post: _size set to passed value, _arrayptr points to
	//			array of that size
	KSArray(size_type size, value_type value) 
		:_arrayptr(new value_type[size], _size(size))
	{
		std::fill(begin(), end(), value);
	}

	// Copy ctor
	// Pre: None
	// Post: _size is set to other array, _arrayptr points to
	//			new array of size _size, contents copied
	KSArray(const KSArray & other) 
		:_arrayptr(new value_type[other._size]), _size(other._size)
	{
		std::copy(other.begin(), other.end(), begin());
	}

	// Copy assignment 
	// Pre: None
	// Post: _size is set to other array, _arrayptr points to
	//			new array of size _size, contents copied
	KSArray & operator=(const KSArray & other)
	{
		KSArray copy(other);
		std::swap(_arrayptr, copy._arrayptr);
		std::swap(_size, copy._size);
		return *this;
	}	
	
	// Move ctor
	// Pre: None
	// Post: _size is set to size rvalue array, _arrayptr
	//			points to value of array
	KSArray(KSArray && other) noexcept
		:_arrayptr(other._arrayptr), _size(other._size)
	{
		other._arrayptr = new value_type[0];
		other._size = 0;
	}

	// Move assignment
	// Pre: None
	// Post: _size is set to size rvalue array, _arrayptr
	//			points to value of array
	KSArray & operator=(KSArray && other) noexcept
	{
		std::swap(_arrayptr, other._arrayptr);
		std::swap(_size, other._size);
		return *this;
	}

//**************************************************//
// General Public Operators
//**************************************************//
public:

	// op[] - const & non-const
	// Pre: 0 <= index (size of allocated array)
	// Post: Return is reference to item index of allocated array
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
//**************************************************//
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
	// _arrayptr: Pointer to dynamic array
	// _size: Size of dynamic array
	value_type * _arrayptr;
	size_type _size;
}; // End class KSArray

//**************************************************//
// Global Operators 
//**************************************************//

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

#endif //#ifndef FILE_MSARRAY_H_INCLUDED
