///////////////////////////////////////////////////////////////////////////////////////////////////
//                         COMPUTER METHODS 3 PRACTICAL TEST 1 (MOCK)
// Name: Ben Moshe Sapo
// Student No: 214527679
// Date: 21/03/2016
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

// ***** QUESTION 3 ******
// Question 3 has 3 parts
// 3.1 Using the MINIMAL "Fraction" class provided, overload the greater than operator to work with
//     objects of class Fraction as a NON-MEMBER FUNCTION.   You may modify the Fraction class to 
//     demonstrate friendship.  DO NOT USE FLOATING POINT MATH!!!
// 3.2 Overload two functions called "add" which take two arguements, an integer and a fraction (in 
//     either order) and return a fraction.  
// 3.3 create a driver program to test your overloaded > operators and your overloaded 

class Fraction {
private:
	int num;				// numerator;
	int denom;				// denominator;
public:
	Fraction(int n, int d) : num(n), denom(d) { };
	void print() { cout << num << "/" << denom; };
	friend int operator > (Fraction frac1, Fraction frac2);
	friend Fraction add(int whole, Fraction frac);
	friend Fraction add(Fraction frac, int whole);
};

//Multiplies whole number by denominator to give it a common denominator then adds it to the numerator
Fraction add(int whole, Fraction frac) {
	Fraction Result((whole * frac.denom) + frac.num, frac.denom);
	return Result;
}
Fraction add(Fraction frac, int whole) {
	return add(whole, frac);
}

//Cross multiplies to create common denominator then compares numerator
int operator > (Fraction frac1, Fraction frac2) {
	int num1, num2;
	num1 = frac1.num * frac2.denom;
	num2 = frac2.num * frac1.denom;
	if (num1 > num2)
		return 1;
	else
		return 0;
}

int main() {
	Fraction frac1(8,10);
	Fraction frac2(3, 4);
	if (frac1 > frac2)
		cout << "It is greater" << endl;
	Fraction Result	= add(1, frac1);
	Result.print();
	cout << endl;
	Result = add(frac2, 1);
	Result.print();
}