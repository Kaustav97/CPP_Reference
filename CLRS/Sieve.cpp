#include <bits/stdc++.h>
using namespace std;

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

void bin(int n){
  for(int i=ceil(log2(n));i>=0;i--){
    cout<<((n & (1<<i))>0)?1:0;
  }
  cout<<endl;
}

int main(){
  int tst; cin>>tst;
  while(tst--){
    int n1,n2; cin>>n1>>n2;
    bin(n1); bin(n2);
    bin(n1*n2);
  }
}
