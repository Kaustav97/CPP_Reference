#include <bits/stdc++.h>

using namespace std;
#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long


int main(){
  int tst; cin>>tst;
  while(tst--){
    priority_queue<int,std::vector<int>,greater<int> > Q;
    int p,c; cin>>p>>c;
    std::vector<int> chk(c);

    rep(c)cin>>chk[i];

    for(int i=1;i<c;i+=2){
      int d1=chk[i]-chk[i-1];
      int d2=INT_MAX;
      if(i+1<c)int d2=chk[i+1]-chk[i];
      Q.push( min(d1,d2) ) ;
    }
    int ans=0;
    rep(p){ans+=pow(Q.top(),2);Q.pop();}
    cout<<ans<<endl;
  }
  
}
