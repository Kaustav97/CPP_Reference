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
  int tst; cin>>tst;
  while(tst--){
    string str; cin>>str;
    int k; cin>>k;
    unordered_set<char> S;
    tr(str)S.insert(*it);
    if(26-S.size()<=k)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
}
