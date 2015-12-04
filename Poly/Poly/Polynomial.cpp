#include<iostream>
#include "Polynomial.h"
#include<assert.h>
using namespace std;

//member function
Polynomial::Polynomial(int size)  //default dctor
{
	set_size_of_array(size);
	array_coefficient=new double[this->size];
	assert(array_coefficient!=0);
	cin>>*this;
	cout<<"poly created!"<<endl;
}
Polynomial ::Polynomial( const Polynomial & polynomial) //copy ctor
{ 
	if (*this!=polynomial)
	{
		if (size!=polynomial.size)
		{
			size=polynomial.size;
			delete [] array_coefficient;
			array_coefficient=new double[size];
		}

		for (int i = 0; i < size; i++)
		{
			array_coefficient[i]=polynomial.array_coefficient[i];
		}
	}

}
void Polynomial::set_size_of_array(int size) //setter
{
	this->size = (size > 0? size:1);
}
int Polynomial::get_size_of_array()const //getter
{
	return size;
}
Polynomial::~Polynomial() // dctor
{
	delete [] array_coefficient;
	cout<<" delete Polynomial"<<endl;
} 
bool Polynomial:: operator == (const Polynomial & right) const
{
	if(this->size!=right.size)
		return false;
	for (int i = 0; i < right.size; i++)
	{
		if(this->array_coefficient[i]!=right.array_coefficient[i])
			return false;
	}
	return true;
}

bool Polynomial:: operator> (const Polynomial & right) const
{
	if(this->size > right.size)
		return true;
	return false;
}

const Polynomial & Polynomial :: operator+= (const Polynomial & right) //operator+=
{
	if(size > right.size){	
		for (int i = 0; i < this->size; i++)
		{
			array_coefficient[i]+=right.array_coefficient[i];
		}
		return *this;
	}
	if (size<right.size)
	{
		size=right.size;
		double *temp_array_of_coefficient=this->array_coefficient; //!!!!!!!!!!!!!!!!!!!!!!!!!!! warning!!!!!!!!!!!!!!!!!!!!!!>
		delete [] this->array_coefficient;
		this->array_coefficient=new double[size];
		//for (int i = 0; i < length; i++)
		{

		}

	}


	return false;
}
const Polynomial & Polynomial :: operator-= (const Polynomial & )const //operator-=
{

	return false;
}
const Polynomial & Polynomial :: operator= (const Polynomial &right) //assignment (array) operator   
{
	if(*this!=right)
	{
		delete []array_coefficient;
		array_coefficient= new double[right.size];
		for (int i = 0; i < right.size; i++)
		{
			array_coefficient[i]=right[i];

		}
	}
	return false;
}
int & Polynomial :: operator[] (int zevel)
{
	return zevel;
}
const int & Polynomial :: operator[] (int zevel)const
{
	return zevel;
}
ostream & operator<<(ostream & output,const Polynomial &polynomial)
{
	for (int i = 0; i < polynomial.size; i++)
	{
		char * sign_pluse=(polynomial.array_coefficient[i] >=0)?"":"+";
		output<<polynomial.array_coefficient[i]<<"X^"<<sign_pluse<<i<<" ";
	}
	output<<endl;
	return output;
}
istream &  operator>>(istream  & input, Polynomial &polynomial)
{
	int i=0;
	//cout<<"please input<< a coefficient of X in ascending order"<<endl;
	while (i <= polynomial.size)
	{
		input >> polynomial.array_coefficient[i];
		i++;
	}
	return input;
}
Polynomial &operator+(Polynomial & p1,Polynomial & p2)
{
	int new_size= (p1.size>p2.size)?p1.size:p2.size;
	Polynomial sum_poly(new_size);
	
	for ( int i = 0; i <= p1.size; i++ )
		sum_poly.array_coefficient[i] += p1.array_coefficient[i];
	for ( int i = 0; i <= p2.size; i++ ) 
		sum_poly.array_coefficient[i] += p2.array_coefficient[i];
    return sum_poly;
}
Polynomial &operator-(Polynomial &,Polynomial&);

