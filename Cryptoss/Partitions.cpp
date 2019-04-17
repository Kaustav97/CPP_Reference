#include <bits/stdc++.h>

using namespace std;
#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second

int part(int n, int k){
  if(n==k | k==1)return 1;
  if(n<k) return 0;
  else return part(n-1,k-1) + part(n-k,k);
}
int main(){
  int q,p; cin>>q>>p;
  cout<<part(q,p)<<endl;
}
