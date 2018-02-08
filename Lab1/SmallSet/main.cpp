#include <iostream>
#include <fstream>
#include "SmallSet.hpp"

int main()
{
  SmallSet * sm = new SmallSet();
  std::cout << "Adding 0: " << sm->addElement(0) <<std::endl;
  std::cout << "Adding 7: " << sm->addElement(7) <<std::endl;
  std::cout << "Adding 3: " << sm->addElement(3) <<std::endl;
  std::cout << "Adding 3: " << sm->addElement(3) <<std::endl;
  //std::cout << "Deleting 3: " << sm->deleteElement(3) <<std::endl;
  sm->printElements();
  //sm->numElements();

  std::cout << "Adding 10: " << sm->addElement(10) <<std::endl;

  sm->printElements();
  //sm->numElements();

  std::cout << "Deleting 7: " << sm->deleteElement(7) <<std::endl;
  std::cout << "Deleting 3: " << sm->deleteElement(3) <<std::endl;

  sm->printElements();
  sm->numElements();
  
  //dumpBits0(sm, 
  //std::cout << "Adding 4: " >> sm->addElement(4) <<std::endl;
  //sm->printElements();
  /*
  int i = 0;
  unsigned long w;
  for (i=0; i < 10; i++)
    {
      std::cout << "What should I add next?" << std::endl;
      std::cin >> (w);
      std::cout << sm->addElement(w) << std::endl;
      sm->printElements();
    }
  sm->numElements();
  */
  
  return 0;
}
