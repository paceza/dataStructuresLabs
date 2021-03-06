#include "SmallSet.hpp"
#include <iostream>
#include <fstream>
#include <math.h>

bool SmallSet::addElement(unsigned long w)
{
  if (isMember(w) || w > 63) 
    return false;
  unsigned long value = 1;
  value = value << w;
  set = set | value;
  return true;
}

bool SmallSet::deleteElement (unsigned long w)
{
  if (!isMember(w) || w > 63)
    return false;
  unsigned long value = 1;
  value = value << w;
  set = set ^ value;
  return true;
}

bool SmallSet::isMember(unsigned long w)
{
  unsigned long value = 1;
  unsigned long temp = set;
  value= value << w;
  temp = value | temp;
  if (w<=63 && w>=0) {
    if (temp == set)
      return true;
  }
  return false;
}

unsigned SmallSet::numElements()
{
  unsigned count = 0;
  unsigned long i = 1;
  while(i)
  {
    count += (set & i ? 1 : 0);
    i = i << 1;
  }
  return count;
}

void SmallSet::printElements()
{/* Original Way, Koosh Disapproved
  unsigned count = 0;
  unsigned long i = set;
  while(i){
    if (i & set)
      std::cout << << std::endl;
    count++;
    i <<= 1;
  }
  return;

  
   #1 way
  for( int i = 0; i < 64; i++)
    if( isMember(i) )
      std::cout << i << std::endl;
  */
  unsigned long pos = 1;
  int value = 0;
  while( pos ) {
    if( pos & set )
      std::cout << value << std::endl;;
    value++;
    pos <<= 1;
  }
  
  /*
  unsigned numBits = 0;
  while (pos) {
    set & pos ? std::cout << 1 : std::cout <<0;
    pos = pos << 1;
    numBits++;
  }
  std::cout <<std::endl;
  */
}
