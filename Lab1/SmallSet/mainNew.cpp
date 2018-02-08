#include<iostream>
#include<fstream>
#include<unistd.h>
#include<stdlib.h>

#include "SmallSet.hpp"

#include<cstdlib>

const int numBits = sizeof(long) * 8;
const bool debug = false;

class InvertedList_PartB
{
public:
  InvertedList_PartB(unsigned size): maxValue(size), numElements(0) {
    randomList = new unsigned[size];
    verifier = new unsigned[size];
    srand( getpid() );
  }

  bool member(unsigned v) {
    return v < maxValue && randomList[v] < numElements && verifier[ randomList[v] ] == v;
  }

  void insert(unsigned v) {
    if( member(v) )
      return;
    randomList[v] = numElements;
    verifier[numElements++] = v;
  }

  void print() {
    for(int i = 0; i < maxValue; i++ )
      if( member(i) )
	std::cout << i << std::endl;
  }

  void remove(unsigned v) {
    if( ! member(v) )
      return;

    // print();
    unsigned idx = randomList[v];
    verifier[ idx ] = verifier[numElements - 1];
    randomList[ verifier[ idx ] ] = idx;
    numElements--;
  }

  int randomElement() {
    if( card() == 0 )
      return -1;

    unsigned idx = random() % numElements;
    return verifier[idx];
  }
  unsigned card() { return numElements; }

  ~InvertedList_PartB() {
    delete [] randomList;
    delete [] verifier;
  }

private:
  unsigned numElements, maxValue;
  unsigned *randomList;
  unsigned *verifier;

};


bool areTheSame(SmallSet *sm, InvertedList_PartB *l_set)
{
  if( sm->numElements() != l_set->card() ) {
    if( debug )
      std::cout << "Your set has " << sm->numElements() << " members but the reference set has " << l_set->card() << std::endl;

    std::cout << "Test failed; the set doesn't have the correct number of elements...\n";
    exit( 1 );
  }
  for( int k = 0; k < numBits; k++ )
    if( sm->isMember(k) && ! l_set->member(k) ) {
      std::cout << k << " is a member of your set but not a member of the reference set.\n";
      exit(1);
    } else if( ! sm->isMember(k) && l_set->member(k) ) {
      std::cout << k << " is a member of the reference set but not a member of your set.\n";
      exit(1);
    }
  return true;
}

void testInsertsAndDeletes(SmallSet *sm, InvertedList_PartB *l_set, int numOps) {
  if( debug )
    std::cout << "Starting the test.\n";
  for( int i = 0; i < numOps; i++ ) {
    int op = rand() % 11;
    if( op <= 6 ) { // 60 % of the times insert a random value
      int v = rand() % numBits;
      if( debug )
	std::cout << "inserting " << v << std::endl;

      sm->addElement(v);
      l_set->insert(v);
    } else { // 40% of the times delete a value
      int v = rand() % numBits;
      if( debug )
	std::cout << "deleting " << v << std::endl;

      sm->deleteElement(v);
      l_set->remove(v);
    }
    if( i % 10 == 0 )  // test set equality once per 10 iterations
      areTheSame(sm, l_set);
  }
  if( debug )
    std::cout << "Test ends.\n";

}


int main()
{
  const int numOps = 200;

  pid_t pid = getpid();
  srand(pid);   // initialize using process id.

  std::cout << "Creating and testing a SmallSet\n";
  SmallSet *sm = new SmallSet();
  InvertedList_PartB *l_set = new InvertedList_PartB(numBits);
  testInsertsAndDeletes(sm, l_set, numOps);

  std::cout << "Creating and testing another SmallSet\n";
  SmallSet *sm2 = new SmallSet();
  InvertedList_PartB *l_set2 = new InvertedList_PartB(numBits);
  testInsertsAndDeletes(sm2, l_set2, numOps);

  std::cout << "Creating and testing another SmallSet\n";
  SmallSet *sm3 = new SmallSet();
  InvertedList_PartB *l_set3 = new InvertedList_PartB(numBits);
  testInsertsAndDeletes(sm3, l_set3, numOps);

  delete sm;
  delete l_set;

  delete sm2;
  delete l_set2;

  delete sm3;
  delete l_set3;


  std::cout << "All okay!\n";

  return 0;
}
