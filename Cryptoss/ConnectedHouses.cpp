#include <bits/stdc++.h>

using namespace std;
#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second

unordered_map<int,vector<int>> grp;
std::vector<int> comp;
set<int> vis;

void trav(int i){
  vis.insert(i);
  tr(grp[i]){
    comp[*it]= comp[i];
    if(vis.find(*it)==vis.end())trav(*it);
  }
}

void edge(int fr,int to){
  grp[to].push_back(fr);
  grp[fr].push_back(to);
}

int main(){
  int n;  cin>>n;
  grp = unordered_map<int,vector<int>>();
  rep(n){
    int f,t; cin>>f>>t;
    edge(f,t);
  }
  comp = std::vector<int>(2*n+1);
  for(int i=0;i<n;i++){
    if(grp[i].size()==0)vis.insert(i);
  }

  cout<<"done!";
  tr(vis)cout<<*it<<" ";

  while(vis.size()!=2*n){
    for(int i=1;i<=2*n;i++){
      if(vis.find(i)==vis.end())trav(i);
    }
  }

  // tr(grp){
  //   cout<<(*it).first<<": ";
  //   rep((*it).second.size())cout<<(*it).second[i]<<" ";
  //   cout<<endl;
  // }

  tr(comp)cout<<*it<<" ";
}
