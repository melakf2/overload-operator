#include<iostream>
#include "Polynomial.h"
using namespace std;
<<<<<<< HEAD
int main()
{
	/*
Polynomial p1( 1.0, -4.0 ); 
Polynomial p2( 15.0, 1.0 ); 
Polynomial p3 = p1 + p2;
Polynomial p3 = p1 * p2;
Polynomial p4(p1)
p2 += p1; 
p2 *= p1; 
p2 = p3*p1; 
p2 -= p1; 
p3 = p1 + p2; 
p2 = p1 + p4; 
p3 = p1 * p3-p2-p1+p4; 
p4 = p1 * p2*p3; 
double k=5.0;
p2=d*p1; 
p2=p1*k;
p2=d*p1;
*/
	return 0;
}
=======
Polynomial &input_polynom(int);
int get_size();
int main()
{

	int selection, max_degree, max_deg_p1, max_deg_p2,  degree;;
	Polynomial main_polynom;
	Polynomial p1, p2;
	do
	{
		cout << "    Menu: Operator Overloading" << endl;
		cout << "  ====================================" << endl;
		cout << "  1. For cin operator press 1" << endl;
		cout << "  2. For cout operator press 2" << endl;
		cout << "  3. For - operator press 3" << endl;
		cout << "  4. For + operator press 4" << endl;
		cout << "  5. For = operator press 5" << endl;
		cout << "  6. For Scalar*Polynom operator press 6" << endl;
		cout << "  7. For Polynom*Scalar operator press 7" << endl;
		cout << "  8. For Polynom*Polynom operator press 8" << endl;
		cout << "  9. For += operator press 9" << endl;
		cout << "  10. For -= operator press 10" << endl;
		cout << "  11. For [] operator press 11" << endl;
		cout << "  12. 0 for Exit" << endl;
		cout << "  ====================================\n";
		cout << "  Enter your selection: " << endl;
		cin >> selection;
		cout << endl;

		if (selection==1){
			cout << "cin operator" << endl;
			degree = get_size();
			Polynomial p(degree + 1);
			cout << endl;
		}
		if (selection == 2){
			cout << "cin operator" << endl;
			degree = get_size();
			Polynomial p(degree + 1);
			cout << p << endl;
			cout << endl;
		}
		if (selection==3){
			degree = get_size();
			Polynomial right(degree + 1);
			degree = get_size();
			Polynomial left(degree + 1);
			left - right;
			cout << "the result is: ";
			cout << left << endl;
			cout << endl;
		}
		if (selection == 4){
			cout << "  + operator" << endl;
			degree = get_size();
			Polynomial right(degree + 1);
			degree = get_size();
			Polynomial left(degree + 1);
			left + right;
			cout << "the result is: ";
			cout << left << endl;
			cout << endl;
		}
		if (selection == 5){
			cout << "  = operator" << endl;
			degree = get_size();
			Polynomial right(degree + 1);
			degree = get_size();
			Polynomial left(degree + 1);
			left = right;
			cout << "the result is: ";
			cout << left << endl;
			cout << endl;
		}
		if (selection == 6){
			int scalar;
			cout << "  scalar*Polynom operator " << endl;
			cout << "enter scalar" << endl;
			cin >> scalar;
			degree = get_size();
			Polynomial right(degree + 1);
			scalar*right;
			cout << "the result is: ";
			cout << right << endl;
			cout << endl;
		}
		if (selection == 7){
			cout << "  Polynom*scalar operator " << endl;
			int scalar;
			cout << "enter scalar" << endl;
			cin >> scalar;
			degree = get_size();
			Polynomial left(degree + 1);
			left*scalar;
			cout << "the result is: ";
			cout << left << endl;
			cout << endl;
		}
		if (selection == 8){
			cout << " Polynom*Polynom operator" << endl;
			degree = get_size();
			Polynomial right(degree + 1);
			degree = get_size();
			Polynomial left(degree + 1);
			Polynomial result = left*right;
			cout << "the result is: ";
			cout << result << endl;
			cout << endl;
		}
		if (selection == 9){
			cout << " += operator" << endl;
			degree = get_size();
			Polynomial right(degree + 1);
			degree = get_size();
			Polynomial left(degree + 1);
			left += right;
			cout << "the result is: ";
			cout << left << endl;
			cout << endl;
		}
		if (selection == 10){
			cout << " -= operator" << endl;
			degree = get_size();
			Polynomial right(degree + 1);
			degree = get_size();
			Polynomial left(degree + 1);
			left -= right;
			cout << "the result is: ";
			cout << left << endl;
			cout << endl;
		}
		if (selection == 11){
			int subscript; 
			double coefficient;
			cout << " [] operator" << endl;
			degree = get_size();
			Polynomial array(degree + 1);
			cout << "enter subscript " << endl;
			cin >> subscript;
			coefficient = array[subscript];
			if (subscript > degree)
				cout << "out of range, the max degree is " << degree << endl;
			else if (coefficient)
			cout << coefficient << "is the coefficient of X^" << subscript << endl;
			else cout << "the coefficient is not exist" << endl;
			cout << endl;
		}
		if (selection == 0)
		{
			exit(0);
		}

	} while (selection != 0);




	return 0;
}
Polynomial& input_polynom(int size)
{
	Polynomial poly(size+1);
	return poly;
}
int get_size()
{
	int degree;
	cout << "Please enter Polynom max degree, attention negetiv number is not valid :" << endl;
	cin >> degree;
	while (degree<0)
	{
		cout << "Please enter Polynom max degree, attention negetiv number is not valid :" << endl;
	    cin >> degree;
	}
	return degree;
}
>>>>>>> 424ebcf1cb2fde8b0218d1b9445341d557677abb
