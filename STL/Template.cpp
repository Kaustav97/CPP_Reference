#include <iostream>
#include <vector>
using namespace std;

template<typename T> void reverse_array(T first,T last){
  if(first!=last){
    while(true){
      // T tmp=*first;
    }
  }
}

void print(vector<int>::iterator a){
  cout<<*a;
}

int main(){
  vector<int> v={1,2,3,4};
  // cout<<*(v.begin());
  reverse_array<vector<int>::iterator> (v.begin(),v.end());
  // print(v.begin());
}
