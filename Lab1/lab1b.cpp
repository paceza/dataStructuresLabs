#include <iostream>

int main()
{
  std::cout << "01111011 & 00000001 = " << (123 & 1)   <<  std::endl;
  std::cout << "01111011 & 00000010 = " << (123 & 2)   <<  std::endl;
  std::cout << "01111011 & 00000100 = " << (123 & 4)   <<  std::endl;
  std::cout << "01111011 & 00001000 = " << (123 & 8)   <<  std::endl;
  std::cout << "01111011 & 00010000 = " << (123 & 16)  <<  std::endl;
  std::cout << "01111011 & 00100000 = " << (123 & 32)  <<  std::endl;
  std::cout << "01111011 & 01000000 = " << (123 & 64)  <<  std::endl;
  std::cout << "01111011 & 10000000 = " << (123 & 128) <<  std::endl;

  return 0;
} 
