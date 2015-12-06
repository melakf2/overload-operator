#include<iostream>
#include "Polynomial.h"
#include<assert.h>
using namespace std;

//member function
Polynomial::Polynomial(){ //default ctor
	size = 1;
	this->array_coefficient = new double[size];
	this->array_coefficient[0] = 0;
}
Polynomial::Polynomial(int size)  //overload ctor
{
	set_size_of_array(size);
	array_coefficient = new double[size];

	assert(array_coefficient != 0);
	cin >> *this;
	cout << "polynomial is : " << *this << endl;
}
Polynomial::Polynomial(const Polynomial & polynomial) //copy ctor
{

			size = polynomial.size;
			array_coefficient = new double[size];
			assert(array_coefficient!=0);
		for (int i = 0; i < size; i++)
			array_coefficient[i] = polynomial.array_coefficient[i];


}
void Polynomial::set_size_of_array(int size) //setter
{
	this->size = (size > 0 ? size : 1);
}
int Polynomial::get_size_of_array()const //getter
{
	return size;
}
Polynomial::~Polynomial() // dctor
{
	delete[] array_coefficient;
	cout << " delete Polynomial" << endl;
}
bool Polynomial:: operator == (const Polynomial & right) const
{
	if (this->size != right.size)
		return false;
	for (int i = 0; i < right.size; i++)
	{
		if (this->array_coefficient[i] != right.array_coefficient[i])
			return false;
	}
	return true;
}

bool Polynomial:: operator>(const Polynomial & right) const
{
	if (this->size > right.size)
		return true;
	return false;
}

const Polynomial & Polynomial :: operator+= (const Polynomial & right) //operator+=
{
	return *this + right;
}
const Polynomial & Polynomial :: operator-= (const Polynomial & right) //operator-=
{

	return *this - right;
}
const Polynomial & Polynomial :: operator= (const Polynomial &right) //assignment (array) operator   
{
	if (*this != right)
	{
		delete[]array_coefficient;
		this->size = right.size;
		array_coefficient = new double[this->size];
		for (int i = 0; i < this->size; i++)
		{
			array_coefficient[i] = right[i];
		}
	}
	return *this;
}

const double & Polynomial :: operator[] (const int k)const
{
	double z = 0;
	if (k >= 0 && k < this->size)
		return array_coefficient[k];
	return z;
}
const Polynomial & Polynomial:: operator*(const Polynomial &right)
{
	int tmp_size = this->size + right.size - 1;
	double *temp = new double[tmp_size];
	for (int j = 0; j < tmp_size; j++)
	{
		temp[j] = 0;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		for (int k = right.size - 1; k >= 0; k--)
		{
			temp[i + k] += this->array_coefficient[i] * right.array_coefficient[k];
		}
	}
	this->size = tmp_size;

	this->array_coefficient = temp;

	return *this;
}
const Polynomial & Polynomial ::operator+(const Polynomial & right)
{
	if (this->size >= right.size){
		for (int i = 0; i < right.size; i++)
		{
			this->array_coefficient[i] += right.array_coefficient[i];;
		}
	}
	if (this->size < right.size)
	{
		for (int i = 0; i < this->size; i++)
			right.array_coefficient[i] += this->array_coefficient[i];

		this->size = right.size;
		delete[] this->array_coefficient;
		this->array_coefficient = new double[this->size];
		for (int i = 0; i < this->size; i++)
		     this->array_coefficient[i] = right.array_coefficient[i];
		
	}

	return *this;
}
const Polynomial & Polynomial ::operator -(const Polynomial& right){

	if (this->size >= right.size){
		for (int i = 0; i < right.size; i++)
		{
			this->array_coefficient[i] -= right.array_coefficient[i];;
		}
	}
	if (this->size < right.size)
	{
		int i = 0;
		for (i; i < right.size; i++)
			right.array_coefficient[i] *= -1;
		for (size_t i = 0; i < size; i++)
		{
			right.array_coefficient[i] += this->array_coefficient[i];
		}
		this->size = right.size;
		delete[] this->array_coefficient;
		this->array_coefficient = new double[this->size];
		this->array_coefficient = right.array_coefficient;
	}
	
	

	return *this;
}
<<<<<<< HEAD


//=========================friend member function==========================//

ostream & operator<<(ostream & output,const Polynomial &polynomial)
=======
//=========================friend member function==========================//

ostream & operator<<(ostream & output, const Polynomial &polynomial)
>>>>>>> 424ebcf1cb2fde8b0218d1b9445341d557677abb
{
	int i = 0, count=polynomial.size;
	bool isPrinted = false;
	char  sign_pluse = ' ';
	for (int i = 0; i < 2 && i < polynomial.size; i++)
	{
		if (polynomial.array_coefficient[i] != 0)
		{
			count--;
			if (i == 0 && polynomial.array_coefficient[i] != 0)
			{
				cout << polynomial.array_coefficient[i];
				i++;
				isPrinted = true;
			}
			sign_pluse = (polynomial.array_coefficient[i] > 0) ? '+' : ' ';
			if (i == 1 && i < polynomial.size && polynomial.array_coefficient[i] != 0)
			{
				cout << sign_pluse << polynomial.array_coefficient[i] << "X";
				isPrinted = true;
			}
		}
	}
	for (i; i < polynomial.size; i++)
	{
		if (isPrinted)sign_pluse = (polynomial.array_coefficient[i] > 0) ? '+' : ' ';
		if (polynomial.array_coefficient[i] != 0)
		{
			count--;
			if (i > 1 && polynomial.array_coefficient[i] != 0){
				output << "" << sign_pluse << polynomial.array_coefficient[i] << "X^" << i << "";
				isPrinted = true;
			}

		}
	}
	if (count == polynomial.size)
		cout << "0" << endl;

	output << endl;
	return output;
}
istream &  operator>>(istream  & input, Polynomial &polynomial)
{
	int i = 0;
	cout << "please input  " << polynomial.size << "  coefficients in ascending order" << endl;
	while (i < polynomial.size)
	{
		input >> polynomial.array_coefficient[i];
		i++;
	}
	return input;
}

Polynomial &operator*(Polynomial &right, const double r)//P1*k
{
<<<<<<< HEAD
	return p1;
}
Polynomial &operator-(Polynomial & p1,Polynomial& p2){
 
	return p1;
}
=======

	for (int i = 0; i < right.size; i++)
	{
		right.array_coefficient[i] *= r;
	}

	return right;
}
Polynomial &operator*(const double r, Polynomial &right)//k*p1
{
	return right*r;
}


>>>>>>> 424ebcf1cb2fde8b0218d1b9445341d557677abb

