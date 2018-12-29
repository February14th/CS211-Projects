#include <iostream>
using namespace std;

typedef double (*FUNC)(double); //given
double integrate(FUNC f, double a, double b); //given

double line(double x);
double square(double x);
double cube(double x);

int main(){
  cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;
  cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl;
  cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;
} //given

double line(double x){
  return x;
} //given

double square(double x){
  return x*x;
} //given

double cube(double x){
  return x*x*x;
} //given

double integrate(FUNC f, double a, double b){
  double sum = 0; //sum
  for (double x = a; x <= b; x = (x + 0.0001)){ //each x between a and b in increments of 0.0001
    sum = sum + (f(x) * 0.0001); //height = f(x) base = 0.0001, given
  }
  return sum;
}