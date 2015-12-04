#pragma once
<<<<<<< HEAD
#pragma once
=======
>>>>>>> db4acc44e24f790379d122bc86d264be4ee195b9
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
	friend Polynomial &operator+(Polynomial &,Polynomial&);
    friend Polynomial &operator-(Polynomial &,Polynomial&);
    friend Polynomial & operator*(const Polynomial &,const Polynomial &);
	friend Polynomial &operator*(int , Polynomial & );

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
	bool operator== (const Polynomial &) const;
	bool operator!= (const Polynomial & right) const { return !(*this == right);};
	bool operator> (const Polynomial &) const;
	bool operator< (const Polynomial & right) const{ return !(*this > right);};
	const Polynomial & operator+= (const Polynomial &); //operator+=
	const Polynomial & operator-= (const Polynomial & )const; //operator-=
	const Polynomial & operator= (const Polynomial &); //assignment (array) operator   

	int & operator[] (int);
	const int & operator[] (int)const;
	
};

#endif