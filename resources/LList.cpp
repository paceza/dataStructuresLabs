#include <iostream>
#include <vector>
// all members are public to avoid writing accessors, mutators
using namespace std;

class Node {

public:
  Node(int x) {
    key = x;
    next = 0;
  }

public:
  int key;
  Node* next;
};

class List {

public:
  List() {
    head = 0;
  }

  List(int x) {
    head = new Node(x);
  }

  void insert(int k) {
    // insert k as the first item of the list
    Node* tmp = new Node(k);
    tmp->next = head;
    head = tmp;
  }

  void print() {
    //  print the list enclosed in { }, separated by comma
    Node* temp = head;
    cout << "{";
    while (temp != 0) {
      cout << temp->key;
      if (temp->next!= 0) cout << ", ";
      temp = temp->next;
    }
    cout << "}";
    cout << endl;
  }

public:
  Node* head;
};

class set{
  // set class a single member
private:
  vector<List*> mems;

public:
  set(int n) {
    // creates a vector of size n containing NULL pointers
    for (int j=0; j < n; ++j)
      mems.push_back(NULL);
  }


  void print() {
    // prints each set by calling print function of List
    for (int j = 0; j < mems.size(); ++j)
      mems[j]->print();
  }

  void merge(set S) {
    // mergs S into this set
    for (int i = 0; i < S.mems.size(); ++i)
      mems.push_back(S.mems[i]);
  }

  static set build(int a[], int s, int k) {
    // build subsets of {a[0], a[1], a[2], ... , a[s-]} of size k
    if (k == 1)
      {
	set x(s);
	for (int i=0; i < s; ++i) {
	  x.mems[i] = new List(a[i]);
	};
	return x;
      }
    else
      if (s == k) {
	set x(1);
	x.mems[0] = new List();
	for (int i = 0; i < k; ++ i)
	  x.mems[0]->insert(a[i]);
	return x;
      }
      else
	{
	  set s1 = build(a,s-1,k);
	  set s2 = build(a,s-1,k-1);
	  for (int i = 0; i < s2.mems.size(); ++i)
	    s2.mems[i]->insert(a[s-1]);
	  s1.merge(s2);
	  return s1;
	}
  }
};

int main() {
  int s, k;
  cout << "Enter the size of the set." << endl;
  cin >> s;
  int a[s];
  cout << "Enter the elements of the set." << endl;
  for (int j=0; j < s; ++j)
    cin >> a[j];
  cout << "Enter the size of the subsets." << endl;
  cin >> k;
  set temp = set::build(a, s, k);
  cout << "output:" << endl;
  temp.print();
}
