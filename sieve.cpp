#include <bits/stdc++.h>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long

void buildprm(ll n,std::vector<ll> &pr){
  std::vector<bool> arr(n,1);
  // ll cls=0;
  for(ll i=2;i<arr.size();){
    pr.push_back(i);
    for(ll j=2;(i*j)<arr.size();j++){
      arr[i*j]=0;
      // cls++;
    }
    i++;
    while(arr[i]!=1)i++;
  }

  // cout<<cls<<" CALLS"<<endl;
}

int main(){
  // int n=1000000000;
  ll n=100000000;

  std::vector<ll> prime;
  buildprm(n,prime);
  // tr1(prime)cout<<*it<<" ";
  // rep(100)cout<<prime[i]<<" ";
  cout<<prime[10000]<<endl;
}
