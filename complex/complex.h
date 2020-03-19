#ifndef __complex_h__	// Avoid double includes
#define __complex_h__	// Prevent double include

#include <iostream>
#include <math.h>

/********************************************************
 * Complex class					*
 *							*
 * Members defined					*
 *	complex()		// Default constructor	*
 *	complex(real, imaginary)// Specify two parts	*
 *				// for construction	*
 *	complex(complex)	// Copy constructor	*
 *							*
 *	real()			// Get real part	*
 *	imaginary()		// Get imaginary part	*
 *							*
 *	set(real, imaginary)	// Set both parts of #	*
 *	set_real(real)		// Set real part of #	*
 *	set_imaginary(imaginary)// Set imaginary part	*
 *							*
 * Operator member functions				*
 *			c -- a complex number		*
 *			s -- a scalar (double)		*
 *	c = c						*
 *	c += c;						*
 *	c += s;						*
 *	c -= c;						*
 *	c -= s;						*
 *	c /= c;						*
 *	c /= s;						*
 *	c *= c;						*
 *	c *= s;						*
 *							*
 * The following functions don't really make a lot of	*
 * sense for complex numbers, but they are defined 	*
 * for the purpose of illustration.			*
 *	c++						*
 *	++c						*
 *	c--						*
 *	--c						*
 *							*
 * Arithmetic operators defined				*
 *	c = c + c;					*
 *	c = s + c;					*
 *	c = c + s;					*
 *	c = c - c;					*
 *	c = s - c;					*
 *	c = c - s;					*
 *	c = c * c;					*
 *	c = s * c;					*
 *	c = c * s;					*
 *	c = c / c;					*
 *	c = s / c;					*
 *	c = c / s;					*
 *	-c						*
 *	+c						*
 *	ostream << c	// Output function		*
 *	istream >> c	// Input function		*
 ********************************************************/
class complex
{
    private:
	//
	// Complex numbers consist of two parts
	//
	double real_part;	// The real part
	double imaginary_part;	// The imaginary part

    public:
	// Default constructor, zero everything
	complex()
	{
	   real_part = 0.0;
	   imaginary_part = 0.0;
	}

	// Copy constructor
	complex(const complex& other_complex)
	{
	    real_part = other_complex.real_part;
	    imaginary_part = other_complex.imaginary_part;
	}
	    
	// Construct a complex out of two real numbers
	complex(double init_real, double init_imaginary=0.0)
	{
	    real_part = init_real;
	    imaginary_part = init_imaginary;
	}

	// Destructor does nothing
	~complex() {}

	//
	// Function to return the parts of the number
	//
	double real() const
	{
	    return (real_part);
	}
	double imaginary() const
	{
	    return (imaginary_part);
	}

	// Functions to set parts of a number
	void set(double real, double imaginary) {
	   real_part = real;
	   imaginary_part = imaginary;
	}

	void set_real(double real) {
	    real_part = real;
	}

	void set_imaginary(double imaginary) {
	    imaginary_part = imaginary;
	}

	complex operator = (const complex& oper2) {
	   complex result(oper2);
	   return (result);
	}

	complex& operator += (const complex& oper2) {
	   real_part += oper2.real();
	   imaginary_part += oper2.imaginary();
	   return (*this);
	}

	complex& operator += (double oper2) {
	   real_part += oper2;
	   return (*this);
	}

	complex& operator -= (const complex& oper2) {
	   real_part -= oper2.real();
	   imaginary_part -= oper2.imaginary();
	   return (*this);
	}

	complex& operator -= (double oper2) {
	   real_part -= oper2;
	   return (*this);
	}

	complex& operator *= (const complex& oper2) {
	   // Place to hold the real part of the result
	   // while we compute the imaginary part
	   double real_result = real_part * oper2.real() - 
				imaginary_part * oper2.imaginary();

	   imaginary_part = real_part * oper2.imaginary() + 
			    imaginary_part * oper2.real(); 

	   real_part = real_result; 
	   return *this; 
	}

	complex& operator *= (double oper2) {
	   real_part *= oper2;
	   imaginary_part *= oper2;
	   return (*this);
	}

	complex& operator /= (const complex& oper2);

	complex& operator /= (double oper2) {
	   real_part /= oper2;
	   imaginary_part /= oper2;
	   return (*this);
	}

	// c++
	complex operator ++(int) {
	   complex result(*this);
	   real_part += 1.0;
	   return (result);
	}

	// ++c
	complex& operator ++() {
	   real_part += 1.0;
	   return (*this);
	}

	// c--
	complex operator --(int) {
	   complex result(*this);
	   real_part -= 1.0;
	   return (result);
	}

	// --c
	complex& operator --() {
	   real_part -= 1.0;
	   return (*this);
	}
};

inline complex operator + (const complex& oper1, const complex& oper2)
{
  return complex(oper1.real()      + oper2.real(), 
		 oper1.imaginary() + oper2.imaginary());
}

inline complex operator + (const complex& oper1, double oper2)
{
  return complex(oper1.real() + oper2, 
		 oper1.imaginary());
}

inline complex operator + (double oper1, const complex& oper2)
{
  return complex(oper1 + oper2.real(), 
		 oper2.imaginary());
}

inline complex operator - (const complex& oper1, const complex& oper2)
{
  return complex(oper1.real()      - oper2.real(), 
		 oper1.imaginary() - oper2.imaginary());
}

inline complex operator - (const complex& oper1, double oper2)
{
  return complex(oper1.real() - oper2, 
		 oper1.imaginary());
}

inline complex operator - (double oper1, const complex& oper2)
{
  return complex(oper1 - oper2.real(), 
		 -oper2.imaginary());
}

inline complex operator * (const complex& oper1, const complex& oper2)
{
  return complex(
    oper1.real() * oper2.real() - oper1.imaginary() * oper2.imaginary(), 
    oper1.real() * oper2.imaginary() + oper1.imaginary() * oper2.real());
}

inline complex operator * (const complex& oper1, const double oper2)
{
  return complex(oper1.real()      * oper2, 
		 oper1.imaginary() * oper2);
}

inline complex operator * (const double oper1, const complex& oper2)
{
  return complex(oper1 * oper2.real(), 
		 oper1 * oper2.imaginary());
}

extern complex operator / (const complex& oper1, const complex& oper2);

inline complex operator / (const double& oper1, const complex& oper2) {
   return (complex(oper1, 0.0) / oper2);
}

inline complex operator / (const complex& oper1, const double& oper2) {
   return (oper1 / complex(oper2, 0.0));
}

inline bool operator == (const complex& oper1, const complex& oper2)
{
  return ((oper1.real() == oper2.real()) && 
	  (oper1.imaginary() == oper2.imaginary()));
}

inline bool operator != (const complex& oper1, const complex& oper2)
{
  return (!(oper1 == oper2));
}

inline complex operator - (const complex& oper1)
{
  return complex(-oper1.real(), -oper1.imaginary());
}

inline complex operator + (const complex& oper1)
{
  return complex(+oper1.real(), +oper1.imaginary());
}

inline std::ostream& operator << (std::ostream& out_file, const complex& number)
{
    out_file << '(' << number.real() << ',' << number.imaginary() << ')';
    return (out_file);
}

extern std::istream& operator >> (std::istream& in_file, complex& number);


#endif /* __complex_h__ */	// Avoid double includes
