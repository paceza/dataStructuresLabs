#include<iostream>

unsigned int numOneBits(unsigned v)
{
  unsigned num1Bits = 0;
  for( unsigned i = 1; i; i <<= 1 )
    num1Bits += (v & i ? 1 : 0);
  return num1Bits;
}

unsigned int numOneBits2(unsigned v)
{
  unsigned num1Bits = 0;
  unsigned pos = 1;
  while( pos ) {
    num1Bits += (v & pos ? 1 : 0);
    pos = pos << 1;
  }
  return num1Bits;
}

int main()
{
  unsigned inValue = 1;
  while( inValue ) {
    std::cout << "Enter a positive integer value: ";
    std::cin >> inValue;
    std::cout << "There are " << numOneBits(inValue) << " 1-bits in " << inValue << std::endl;
    std::cout << "There are " << numOneBits2(inValue) << " 1-bits in " << inValue << std::endl;
  }

}
