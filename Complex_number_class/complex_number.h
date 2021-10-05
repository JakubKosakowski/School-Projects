#ifndef complex_numbers_H
#define complex_numbers_H

// define PI value to find angle in cos
#define PI 3.14159265

#include <iostream>
#include <cmath>

using namespace std;

class Complex_number{
private:
	/// Real number
	double re; 
	/// Multiple of imaginary number
	double im;	
	/// Real number after conjugate
	double re_con;
	/// Multiple of imaginary number after conjugate
	double im_con;
	/// Complex number modulus z= re + im * i; modulus = sqrt(re*re + im*im)
	double modulus;
	/// Cosine of directed angle
	double cosine;
	/// Sine of directed angle
	double sine;
	/// Unit of directed angle = arg z
	int angle;
public:
	/**
	 * @brief Construct a new Complex_number object
	 * 
	 */
	Complex_number();

	/**
	 * @brief Complex number constructor with only real number
	 * @param: double
	*/
	Complex_number(double);

	/**
	 * @brief Class constructor
	 * @param: double, double
	*/
	Complex_number(double, double);

	/**
	 * @brief Copy constructor
	 * 
	 * @param const Complex_number*
	 */
	Complex_number(const Complex_number*);

	/**
	 * @brief Copy assignment
	 * 
	 * @param const Complex_number*
	 * @return Complex_number& 
	 */
	Complex_number& operator=(const Complex_number*);

	/**
		*@brief Function print all informations about complex number
	*/
	void print_cn();

	/**
	 * @brief Count complex number modulus
	 * @param double double
	 * @return double 
	 */
	double count_modulus(double, double);

	/**
	 * @brief Return new class object, which is sum of complex numbers
	 * @param const Complex_number*
	 * @param const Complex_number*
	 * @return Complex_number
	 */
	Complex_number complex_sum(const Complex_number*, const Complex_number*);

	/**
	 * @brief Show sum of this complex_number object with other complex_number object
	 * @param const Complex_number*
	 */
	void complex_sum(const Complex_number*);

	/**
	 * @brief Count multiple of complex numbers
	 * 
	 * @return Complex_number 
	 * @param const Complex_number*
	 * @param const Complex_number*
	 */
	Complex_number complex_multiple(const Complex_number*, const Complex_number*);

	/**
	 * @brief Show multiple of this complex_number object with other complex_number object
	 * 
	 * @param const Complex_number*
	 */
	void complex_multiple(const Complex_number*);

	/**
	 * @brief Count divide of complex numbers
	 * 
	 * @return Complex_number
	 * @param const Complex_number*
	 * @param const COmplex_number*
	 */
	Complex_number complex_divide(const Complex_number*, const Complex_number*);

	/**
	 * @brief Perform complex number conjugate
	 * 
	 */
	void complex_conjugate();

	/**
	 * @brief Show complex number conjugate
	 * 
	 */
	void show_conjugate();

	/**
	 * @brief Function show distance between two point on Euclidean Space delineated by two ordered pairs
	 * 
	 * @param const Complex_number*
	*/
	void distance(const Complex_number*);

	double distance(const Complex_number*, const Complex_number*);

	/**
	 * @brief Function count cosine of directed angle; Cos a = (Re z)/|z|
	 * 
	 * @param double Real number
	 * @param double Modulus
	 * 
	 * @return Cosine
	 */
	double count_cosine(double, double);

	/**
	 * @brief Function count sine of directed angle; Sin a = (Im z)/|z|
	 * 
	 * @param double Multiple of imaginary number
	 * @param double Modulus
	 * 
	 * @return Sine
	 */
	double count_sine(double, double);

	/**
	 * @brief Function count unit of directed angle
	 * 
	 * @param double Complex number Cosine
	 * 
	 * @return Angle
	 */
	double count_arg(double);
	/**
	 * @brief Count power of complex number using de Moivre formula
	 * 
	 * @param int Power
	 */
	void de_Moivre(int n);
};


#include "complex_number.cpp"

#endif //complex_numbers_H
