#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

void tobin(int n){
  for(int i=floor(log2(abs(n))) ;i>=0;i-- ){
    cout<<((n & (1<<i))>0);
  }
  cout<<endl;
}

int main(){
  int n1=-10, n2=-25;
  cout<<(n1^n2);
}
