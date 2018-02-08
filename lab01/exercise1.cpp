#include<iostream>

int f(int n){
  if (n==1) return 1;
  else
    return f(n-3)+ n;
}

int main(){
  int inValue;
  std::cout << "Hit me with a number, I'll give you an answer" << std::endl;
  std::cin >> inValue;
  std::cout << f(inValue) << std::endl;
  
}
