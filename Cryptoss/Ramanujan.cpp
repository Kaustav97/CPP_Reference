#include <bits/stdc++.h>

using namespace std;
#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second

int main(){
  int n; cin>>n;

  std::vector<int> v(n);
  unordered_set<int> S;

  rep(n){
    cin>>v[i];
    S.insert(v[i]);
  }

  int ans=0;
  for(int i=0;i<n;i++){
    unordered_set<int> cnt(S);
    bool flg=0;
    cnt.erase(v[i]);

    // tr(cnt)cout<<*it<<" ";
    // cout<<endl;

    for(int j=i+1;j<n;j++){
      cnt.erase(v[j]);
      if(cnt.size()==0){ans+=n-j;flg=1;break;}
    }

    if(flg==0)break;

  }

  cout<<ans<<endl;


}
