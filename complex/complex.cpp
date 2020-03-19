#include "complex.h"

/********************************************************
 * c = c / c -- complex division			*
 *							*
 * Parameters						*
 *	oper1, oper2 -- two operands of the divide	*
 *							*
 * Returns						*
 *	result of the divide				*
 ********************************************************/
complex operator / (const complex& oper1, const complex& oper2)
{
  // Denominator of the result
  double den = fabs(oper2.real()) + fabs(oper2.imaginary());

  // Real part of the oper1 factor
  double oper1_real_den = oper1.real() / den;
  // Imaginary part of the oper1 factor
  double oper1_imag_den = oper1.imaginary() / den;

  // Real part of the oper2 factor
  double oper2_real_den = oper2.real() / den;
  // Imaginary part of the oper2 factor
  double oper2_imag_den = oper2.imaginary() / den;

  // Normalization factor
  double normalization   = oper2_real_den * oper2_real_den + 
			   oper2_imag_den * oper2_imag_den;

  return complex((oper1_real_den * oper2_real_den + 
		  oper1_imag_den * oper2_imag_den) / normalization,
                 (oper1_imag_den * oper2_real_den - 
		  oper1_real_den * oper2_imag_den) / normalization);
}

/********************************************************
 *  c /= c -- complex divide by				*
 *							*
 * Parameters						*
 *	oper2 -- operator to divide by			*
 *							*
 * Returns						*
 * 	Reference to the result of the divide		*
 ********************************************************/
complex& complex::operator /= (const complex& oper2)
{
  // Denominator of the result
  double den = fabs(oper2.real()) + fabs(oper2.imaginary());

  // Denominator -- operator 1 real part
  double oper1_real_den = real_part / den;

  // Denominator -- operator 1 imaginary part
  double oper1_imag_den = imaginary_part / den;

  // Denominator -- operator 2 real part
  double oper2_real_den = oper2.real() / den;

  // Denominator -- operator 2 imaginary part
  double oper2_imag_den = oper2.imaginary() / den;

  // Normalization factor
  double normalization = oper2_real_den * oper2_real_den + 
			 oper2_imag_den * oper2_imag_den;
  real_part      = (oper1_real_den * oper2_real_den + 
		    oper1_imag_den * oper2_imag_den) / normalization;
  imaginary_part = (oper1_imag_den * oper2_real_den - 
		    oper1_real_den * oper2_imag_den) / normalization;
  return (*this);
}

/********************************************************
 * istream >> complex -- read a complex number		*
 *							*
 * Parameters						*
 *	in_file -- file to read				*
 *	number -- place to put the number		*
 *							*
 * Returns						*
 *	reference to the input file			*
 ********************************************************/
std::istream& operator >> (std::istream& in_file, complex& number)
{
    double real, imaginary;  // Real and imaginary part.
    char ch;		// Random character used to verify input

    number.set(0.0, 0.0);	// Initialize the number (just in case)

    // Sentry to protect the I/O
    std::istream::sentry the_sentry(in_file, true);	

    if (the_sentry)
    {
	if (in_file.bad()) return (in_file);	

	in_file >> ch;	// Get character after whitespace
	if (ch != '(') {
	    in_file.setstate(std::ios::failbit);// We have an error
	    return (in_file);
	}

	in_file >> real;

	if (in_file.bad()) return (in_file);

	in_file >> std::ws >> ch;	// Get first character after number

	if (in_file.bad()) return (in_file);

	if (ch != ',') {
	   in_file.setstate(std::ios::failbit);
	   return (in_file);
	}

	in_file >> imaginary;

	in_file >> std::ws >> ch;
	if (in_file.bad()) return (in_file);

	if (ch != ')') {
	   in_file.setstate(std::ios::failbit);
	   return (in_file);
	}
	number.set(real, imaginary);
    }
    else
    {
       in_file.setstate(std::ios::failbit);
    }
   return (in_file);
}
