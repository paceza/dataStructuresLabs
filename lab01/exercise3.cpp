#include <iostream>

int f(int n){
  if(n == 1) return 0;
  else if(n%2 == 0) return 1 + f(n/2);
  else return 2 + f((n - 1) / 2);
}

int main(){
  long long num;
  std::cout << "enter a number" << std::endl;
  std::cin >> num;
  std::cout << f(num) << std::endl;
}
