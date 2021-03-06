#ifndef POLYNOMIAL_H
#define POYNOMIAL_H
#include <iostream>
using namespace std;
class Polynomial
{   	
private:
	
	//=======data member=======//
	double * array_coefficient;
	int size;

public:	
	//==============member function===================//	
	Polynomial();
	Polynomial(int); // ctor with degree zero & arr size is 1
	~Polynomial(); // dctor
	Polynomial( const Polynomial &); //copy ctor
	void set_size_of_array(int); //setter 
	int get_size_of_array()const; //getter

	//==================opertor-overloading========================///
	bool operator== (const Polynomial &) const;
	bool operator!= (const Polynomial & right) const { return !(*this == right);};
	bool operator> (const Polynomial &) const;
	bool operator< (const Polynomial & right) const{ return !(*this > right);};
	const Polynomial & operator+= (const Polynomial &); //p1+=p1
	const Polynomial & operator-= (const Polynomial & ); // p1-=p2
	const Polynomial &operator*=(const Polynomial & );//p1*=p2
	const Polynomial & operator= (const Polynomial &); //assignment (array) operator p1=p2   
	const Polynomial &operator*(const Polynomial & );//p1*p2
	const Polynomial & operator+(const Polynomial &); // p1+p2
	const Polynomial & operator-(const Polynomial &);// p1-p2
	const double & operator[] (const int)const; // return value by index

	//===================non member function=================================//
	friend ostream & operator<<(ostream & output,const Polynomial &polynomial);
	friend istream & operator>>(istream  & input, Polynomial &polynomial);
	
	//==non-member function, get two arguments, unlike non-static member function that get one argument.==//
	friend Polynomial &operator-(const double,Polynomial&);//p1-p2
	friend Polynomial &operator*(Polynomial &, const double);//p1*k
	friend Polynomial &operator*(const double , Polynomial&);//k*p
};

#endif