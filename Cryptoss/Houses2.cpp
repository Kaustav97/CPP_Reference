#include <bits/stdc++.h>

using namespace std;
#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long

unordered_map<int,std::vector<int> >grp;
unordered_set<int> vis;
std::vector<int> comp;

void edge(int fr,int to){
  grp[fr].push_back(to);
  grp[to].push_back(fr);
}

void dfs(int i){
  vis.insert(i);
  tr(grp[i]){
    comp[*it]= comp[i];
    if(vis.find(*it)==vis.end())dfs(*it);
  }
}

int main(){
  int n; cin>>n;
  rep(n){
    int t,f;
    cin>>t>>f;
    edge(t,f);
  }
  comp= std::vector<int>(2*n+1);
  rep(2*n)comp[i+1]=i+1;

  for(int i=1;i<=2*n;i++){
    if(vis.find(i)==vis.end())dfs(i);
  }
  unordered_map<int,int> cnt;
  tr(comp)cnt[*it]++;
  int mn=INT_MAX,mx=0;
  tr(cnt){
    if(it->second>1){
      if(it->second>mx)mx=it->second;
      if(it->second<mn)mn=it->second;
    }
  }
  cout<<mn<<" "<<mx<<endl;
}
