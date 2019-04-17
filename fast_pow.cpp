#include <bits/stdc++.h>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define M 1000000007
#define ll long long

// a^b
int fast_pow(ll a,ll b){
  if(b==0)return 1;
  if(b==1)return a;

  ll half=fast_pow(a,b/2)%M;
  if(b%2)return ( ( (half*half)%M ) *a) %M ;
  else return (half*half)%M;
}
int main(){
  cout<<fast_pow();
}
