// Zack Pace
// Exercise 2
// January 23 2017
#include <iostream>
#include <string>
using namespace std;

// Recursive function to calculate exponents
double exp(double x, double n){
  if (n == 0)
    return 1; // basecase n=0
  else
    return x * exp(x, n-1); // multiply base 'x' * exponent
}

int main(){
  double x,n;
  cout << "give me a number" << endl;
  cin >> x;
  cout << "give me a power" << endl;
  cin >> n;
  cout << exp(x,n) << endl;
  
}
