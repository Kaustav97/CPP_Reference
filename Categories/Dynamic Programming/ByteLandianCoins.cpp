#include <bits/stdc++.h>
using namespace std;

#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second

int main(){
  std::vector<int> v={3,4,10,12,50};
  swap(v[0],v[3]);
  tr1(v)cout<<*it<<" ";
}
