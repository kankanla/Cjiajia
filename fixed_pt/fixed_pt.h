#ifndef __fixed_pt_h__	// Avoid double includes
#define __fixed_pt_h__	// Prevent double include

#include <iostream>
#include <assert.h>
#include <stdlib.h>

namespace fixed_pt {

/* Note: This should be made into a template so that multiple
 * fixed points may be used, but the purpose of this class
 * is to teach operator overloading and templates would be a
 * needless complication.
 */

const int fixed_exp = 100;	// 10**fixed_point */

/* Fudge factor to make doubles into fixed point numbers */
const double fixed_fudge_factor = 0.0001; 


/********************************************************
 * Fixed point class					*
 *							*
 * Members defined					*
 *	fixed_pt()		// Default constructor	*
 *	fixed_pt(double)	// Specifiy an inital	*
 *				// value		*
 *	fixed_pt(fixed_pt)	// Copy constructor	*
 *							*
 *	set(double)		// Set the value	*
 *	double get();		// Return the value 	*
 *				// as a double		*
 *							*
 * Operator member functions				*
 *			f -- a fixed_pt number		*
 *			s -- a scalar (double)		*
 *	f = f						*
 *	f += f;						*
 *	f += s;						*
 *	f -= f;						*
 *	f -= s;						*
 *	f /= f;						*
 *	f /= s;						*
 *	f *= f;						*
 *	f *= s;						*
 *	f++						*
 *	++f						*
 *	f--						*
 *	--f						*
 *							*
 * Arithmetic operators defined				*
 *	f = f + f;					*
 *	f = s + f;					*
 *	f = f + s;					*
 *	f = f - f;					*
 *	f = s - f;					*
 *	f = f - s;					*
 *	f = f * f;					*
 *	f = s * f;					*
 *	f = f * s;					*
 *	f = f / f;					*
 *	f = s / f;					*
 *	f = f / s;					*
 *	-f						*
 *	+f						*
 *	ostream << f	// Output function		*
 *	istream >> f	// Input function		*
 ********************************************************/
class fixed_pt
{
    private:
	long int value;	// Value of our fixed point number

	static long int double_to_fp(const double the_double) {
	    return (
		static_cast<long int>(
		    the_double *
		    static_cast<double>(fixed_exp) +
		    fixed_fudge_factor));
	}


    public:
	// Default constructor, zero everything
	fixed_pt(): value(0) { }

	// Copy constructor
	fixed_pt(const fixed_pt& other_fixed_pt) :
	    value(other_fixed_pt.value)
	{ }
	    
	// Construct a fixed_pt out of a double
	fixed_pt(const double init_real) :
	    value(double_to_fp(init_real))
	{}

	// Destructor does nothing
	~fixed_pt() {}

	// Function to set the number
	void set(const double real) {
	    value = double_to_fp(real);
		    
	}

	// Function to return the value
	double get() const {
	    return (static_cast<double>(value) / fixed_exp);
	}

	// Note: Because of the way we store internal data
	// we do not have to check for self assignment
	fixed_pt operator = (const fixed_pt& oper2) {
	   value = oper2.value;
	   return (*this);
	}

	fixed_pt& operator += (const fixed_pt& oper2) {
	   value += oper2.value;
	   return (*this);
	}

	fixed_pt& operator += (double oper2) {
	   value += double_to_fp(oper2);
	   return (*this);
	}

	fixed_pt& operator -= (const fixed_pt& oper2) {
	   value -= oper2.value;
	   return (*this);
	}

	fixed_pt& operator -= (double oper2) {
	   value -= double_to_fp(oper2);
	   return (*this);
	}

	fixed_pt& operator *= (const fixed_pt& oper2) {
	   value *= oper2.value;
	   value /= fixed_exp;
	   return *this; 
	}

	fixed_pt& operator *= (double oper2) {
	   value *= double_to_fp(oper2);
	   value /= fixed_exp;
	   return (*this);
	}

	fixed_pt& operator /= (const fixed_pt& oper2) {
	    assert(oper2.value != 0.0);
	    value /= oper2.value;
	    value *= fixed_exp;
	}

	fixed_pt& operator /= (double oper2) {
	    assert(double_to_fp(oper2) != 0.0);
	    value /= double_to_fp(oper2);
	    value *= fixed_exp;
	    return (*this);
	}

	// f++
	fixed_pt operator ++(int) {
	   fixed_pt result(*this);
	   value += fixed_exp;
	   return (result);
	}

	// ++f
	fixed_pt& operator ++() {
	   value += fixed_exp;
	   return (*this);
	}

	// f--
	fixed_pt operator --(int) {
	   fixed_pt result(*this);
	   value -= fixed_exp;
	   return (result);
	}

	// --f
	fixed_pt& operator --() {
	   value -= fixed_exp;
	   return (*this);
	}

    private:
	// Used for internal conversions for our friends
	fixed_pt(const long int i_value) : value(i_value){}

    friend fixed_pt operator + (const fixed_pt& oper1, const fixed_pt& oper2);
    friend fixed_pt operator + (const fixed_pt& oper1, const double oper2);
    friend fixed_pt operator + (const double oper1, const fixed_pt& oper2);

    friend fixed_pt operator - (const fixed_pt& oper1, const fixed_pt& oper2);
    friend fixed_pt operator - (const fixed_pt& oper1, const double oper2);
    friend fixed_pt operator - (double oper1, const fixed_pt& oper2);

    friend fixed_pt operator * (const fixed_pt& oper1, const fixed_pt& oper2);
    friend fixed_pt operator * (const fixed_pt& oper1, const double oper2);
    friend fixed_pt operator * (double oper1, const fixed_pt& oper2);

    friend fixed_pt operator / (const fixed_pt& oper1, const fixed_pt& oper2);
    friend fixed_pt operator / (const fixed_pt& oper1, const double oper2);
    friend fixed_pt operator / (const double& oper1, const fixed_pt& oper2);

    friend bool operator == (const fixed_pt& oper1, const fixed_pt& oper2);
    friend fixed_pt operator - (const fixed_pt& oper1);
    friend std::ostream& operator << (std::ostream& out_file, const fixed_pt& number);
    friend std::istream& operator >> (std::istream& in_file, fixed_pt& number);
};

inline fixed_pt operator + (const fixed_pt& oper1, const fixed_pt& oper2)
{
  return fixed_pt(oper1.value + oper2.value);
}

inline fixed_pt operator + (const fixed_pt& oper1, const double oper2)
{
  return fixed_pt(oper1.value + fixed_pt::double_to_fp(oper2));
}

inline fixed_pt operator + (double oper1, const fixed_pt& oper2)
{
  return fixed_pt(fixed_pt::double_to_fp(oper1) + oper2.value);
}

inline fixed_pt operator - (const fixed_pt& oper1, const fixed_pt& oper2)
{
  return fixed_pt(oper1.value - oper2.value);
}

inline fixed_pt operator - (const fixed_pt& oper1, const double oper2)
{
  return fixed_pt(oper1.value - fixed_pt::double_to_fp(oper2));
}

inline fixed_pt operator - (double oper1, const fixed_pt& oper2)
{
  return fixed_pt(fixed_pt::double_to_fp(oper1) - oper2.value);
}

inline fixed_pt operator * (const fixed_pt& oper1, const fixed_pt& oper2)
{
    return fixed_pt(oper1.value * oper2.value / fixed_exp);
}

inline fixed_pt operator * (const fixed_pt& oper1, const double oper2)
{
    return fixed_pt(oper1.value * fixed_pt::double_to_fp(oper2) / fixed_exp);
}

inline fixed_pt operator * (const double oper1, const fixed_pt& oper2)
{
    return fixed_pt(fixed_pt::double_to_fp(oper1) * oper2.value / fixed_exp);
}

inline fixed_pt operator / (const fixed_pt& oper1, const fixed_pt& oper2) 
{
    assert(oper2.value != 0);
    return fixed_pt((oper1.value * fixed_exp) / oper2.value);
}


inline fixed_pt operator / (const double& oper1, const fixed_pt& oper2) 
{
    assert(oper2.value != 0);
    return fixed_pt((fixed_pt::double_to_fp(oper1) * fixed_exp) / oper2.value);
}

inline fixed_pt operator / (const fixed_pt& oper1, const double oper2) 
{
    assert(oper2 != 0);
    return fixed_pt((oper1.value  * fixed_exp) / fixed_pt::double_to_fp(oper2));
}

inline bool operator == (const fixed_pt& oper1, const fixed_pt& oper2)
{
    return (oper1.value == oper2.value);
}

inline bool operator != (const fixed_pt& oper1, const fixed_pt& oper2)
{
    return (!(oper1 == oper2));
}

inline fixed_pt operator - (const fixed_pt& oper1)
{
    return fixed_pt(-oper1.value);
}

inline fixed_pt operator + (const fixed_pt& oper1)
{
    return fixed_pt(oper1);
}

inline std::ostream& operator << (std::ostream& out_file, const fixed_pt& number)
{
    long int before_dp = number.value / fixed_exp;
    long int after_dp1  = abs(number.value % fixed_exp);
    long int after_dp2  = after_dp1 % 10;
    after_dp1 /= 10;

    out_file << before_dp << '.' << after_dp1 << after_dp2;
    return (out_file);
}

extern std::istream& operator >> (std::istream& in_file, fixed_pt& number);

}
#endif /* __fixed_pt_h__ */	// Avoid double includes


