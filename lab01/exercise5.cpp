// Zack Pace
// Jan/23/17
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> gray(int n){
  // basecase n = 1
  // length 3 will be called 3 times to get down to the basecase
  // the amount of results you have based on n is 2^n
  //Create a vector with basecase [0,1]
  vector<string> v;
  vector<string> u;
  v.push_back("0");
  v.push_back("1");

  if (n == 1)
    return v;
  else{
    v = gray(n-1); // Copy
    cout << "Recursive call v" << endl;
    int size = v.size();
    for(int i=0; i < size; ++i){
      u.push_back(v[i] + "0");
    }
    for(int i=0; i < size; ++i){
      u.push_back(v[i] + "1");
    }
    return u;
  }
}

int main(){
  int num;
  cout << "How long do you want your Gray Code to be?" << endl;
  cin >> num;
  vector<string> out = gray(num);
  for (int i = 0; i < out.size(); i++)
    cout << out[i] << endl;
}
