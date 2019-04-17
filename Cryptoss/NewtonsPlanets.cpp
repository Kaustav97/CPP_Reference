#include <bits/stdc++.h>

using namespace std;
#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr1(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second

int main(){
  vector<int> d2={6,2,4,8};
  vector<int> d3={1,3,9,7};
  vector<int> d4={6,4};
  vector<int> d7={1,7,9,3};
  vector<int> d8={6,8,4,2};
  vector<int> d9={1,9};

  int tst; cin>>tst;
  while(tst--){
    ll m,k; cin>>m>>k;
    if(k==0){cout<<1<<endl;continue;}

    switch(m%10){
    case 0 : cout<<0<<endl;break
    case 1 : cout<<1<<endl; break;
    case 2 : cout<<d2[k%4]<<endl; break;
    case 3 : cout<<d3[k%4]<<endl; break;
    case 4 : cout<<d4[k%2]<<endl; break;
    case 5 : cout<<5<<endl; break;
    case 6 : cout<<6<<endl; break;
    case 7 : cout<<d7[k%4]<<endl; break;
    case 8 : cout<<d8[k%4]<<endl; break;
    case 9 : cout<<d9[k%2]<<endl; break;
    }

  }
}
