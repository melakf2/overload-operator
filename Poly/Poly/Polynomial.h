#pragma once
#ifndef POLYNOMIAL_H
#define POYNOMIAL_H
#include <iostream>
using namespace std;
class Polynomial
{   	
    //non member function
	friend ostream & operator<<(ostream & output,const Polynomial &polynomial);
	friend istream & operator>>(istream  & input, Polynomial &polynomial);
	//non-member function, get two arguments, unlike non-static member function that get one argument.
	friend Polynomial & operator*(const double,const Polynomial &);
	friend Polynomial &operator+(const double ,Polynomial&);
	friend Polynomial &operator-(const double,Polynomial&);

protected:
	//data member
	double * array_coefficient;
	int size;
public:
	//member function
	Polynomial(int=1); // ctor with degree zero & arr size is 1
	~Polynomial(); // dctor
	Polynomial( const Polynomial &); //copy ctor
	void set_size_of_array(int); //setter 
	int get_size_of_array()const; //getter

	//opertor-overloading
	bool operator== (const Polynomial &) const;
	bool operator!= (const Polynomial & right) const { return !(*this == right);};
	bool operator> (const Polynomial &) const;
	bool operator< (const Polynomial & right) const{ return !(*this > right);};
	const Polynomial & operator+= (const Polynomial &); //operator+=
	const Polynomial & operator-= (const Polynomial & )const; // p1-=p2
	const Polynomial &operator*=(const Polynomial & );//p1=p3*p2
	const Polynomial & operator= (const Polynomial &); //assignment (array) operator p1=p2   
	const Polynomial &operator*(const Polynomial & );//p1*=p2
	const Polynomial &operator*(const double);// p1*=k
	const Polynomial & operator+(const Polynomial &)const; // p1+k
	const Polynomial & operator+(const double)const; // p1-k
	const Polynomial & operator-(const Polynomial &);// p1+p2
	const Polynomial & operator-(const Polynomial & )const; //p1-p2
	int & operator[] (int);
	const int & operator[] (int)const;

};

#endif