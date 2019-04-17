#include <bits/stdc++.h>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second

d

int main(){
  std::vector<int> stk={10,11,7,10,6};
  std::vector<int> chg;

  for(int i=1;i<stk.size();i++){
    chg.push_back(stk[i]-stk[i-1]);
  }

  // tr1(chg)cout<<*it<<" ";
  // cout<<endl;



}
