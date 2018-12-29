// Rat class i.e. a class for rational numbers
#include <iostream>
using namespace std;

class Rat {
  
private:
	int n; //numerator
	int d; //denominator

public:
	// constructors

	// default constructor
	Rat() {
		n = 0;
		d = 1;
	}

	// 2 parameter constructor
	Rat(int i, int j) {
		n = i;
		d = j;
	}
	// conversion constructor
	Rat(int i) {
		n = i;
		d = 1;
	}

	// accessor functions (usually called get() and set(...) )
	int getN() {
		return n;
	}
	int getD() {
		return d;
	}
	void setN(int i) {
		n = i;
	}
	void setD(int i) {
		d = i;
	}

	// arithmetic operators

	Rat operator+(Rat r) {
		Rat t;
		t.n = n * r.d + d * r.n;
		t.d = d * r.d;
		return t;
	}
	
	Rat operator-(Rat r){
	  Rat t;
	  t.n = n * r.d - d * r.n;
	  t.d = d * r.d;
	  return t;
	}
	
	Rat operator*(Rat r){
	  Rat t;
	  t.n = n * r.n;
	  t.d = d * r.d;
	  return t;
	}
	
	Rat operator/(Rat r){
	  Rat t;
	  t.n = n * r.d;
	  t.d = d * r.n;
	  return t;
	}

	// 2 overloaded i/o operators
	friend ostream &operator<<(ostream &os, Rat r);
	friend istream &operator>>(istream &is, Rat &r);
}; // end Rat

int gcd(int i, int j){ // finding gcd for lowest terms
  if(j == 0) return i;
  return gcd(j, i % j);
}

// operator<<() is NOT a member function but since it was declared a friend of
// Rat
// it has access to its private parts.
ostream &operator<<(ostream &os, Rat r) {
  
  if(r.n >= r.d){ // test for improper fraction, if numerator >= denominator
    if((r.n) % (r.d) == 0){ // whole numbers
      os << (r.n) / (r.d) << endl;
      return os;
    }
    
    
    if(r.d < 0 && (r.n * -1) < r.d){
     int n = gcd(r.n % r.d, r.d);
      os << (r.n) / (r.d) << "   " << ((r.n) % (r.d)) / n << " / " << (r.d) / n * -1 << endl;
      // *-1 because negative was already shown in the whole number
      return os;
    }
    
    
    
    // mixed numbers, whole number followed by proper fraction
    int n = gcd(r.n % r.d, r.d);
    os << (r.n) / (r.d) << "   " << ((r.n) % (r.d)) / n << " / " << (r.d) / n << endl;
    return os; // dividing by the gcd to get the lowest term
  }
  
  if((r.n) % (r.d) == 0){ // whole numbers
      os << (r.n) / (r.d) << endl;
      return os;
    } // repeat again in case numerator or denominator is negative, thus bypassing previous if statements
    
  if((r.n * -1) >= r.d){
    int n = gcd(r.n % r.d, r.d);
    if(r.d < 0){
      os << (r.n) / (r.d) << "   " << ((r.n) % (r.d)) / n << " / " << (r.d) / n  << endl;
      return os;
    }
    os << (r.n) / (r.d) << "   " << ((r.n) % (r.d)) / n << " / " << (r.d) / n * -1 << endl; 
    // *-1 because negative was already shown in the whole number
    return os; // dividing by the gcd to get the lowest term
  } // testing for negative numerator  negative denominator
  
  if(r.n == 0){
    os << r.n << endl;
    return os;
  } // cout 0 if numerator is 0, no point printing 0/5 if its just 0
  
  int n = gcd(r.n % r.d, r.d);
	os << r.n / n << " / " << r.d / n << endl;
	return os;
}
// operator>>() is NOT a member function but since it was declared a friend of
// Rat
// it has access to its provate parts.
istream &operator>>(istream &is, Rat &r) {
	is >> r.n >> r.d;
	return is;
}

int main() {
	Rat x(1, 2), y(2, 3), z;
	z = x + y;
	cout << z;

	x.setN(3);
	y.setD(2);
	z = x + y;
	cout << z;
	cin >> x;
	cout << x;
	z = x + 5;
	cout << z;
	return 0;
}