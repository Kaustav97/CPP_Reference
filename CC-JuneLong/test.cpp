#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int main(){
  string a="ABCD";
  char b=a[a.size()-1];
  a.insert(0,1,b);
  cout<<a;
}
