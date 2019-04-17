#include <bits/stdc++.h>
using namespace std;

# define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++ )
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

std::vector<vector<pair<int,int>> > V;
void edg(int fr,int to,int wt,std::vector<std::vector<pair<int,int>> > &grp=V){
  grp[fr].push_back(make_pair(to,wt));
  grp[to].push_back(make_pair(fr,wt));
}

void disp(std::vector<std::vector<pair<int,int>> > &V){
  rep(V.size()){
    cout<<i<<": ";
    tr1(V[i])cout<<"("<<it->first<<","<<it->second<<") ";
    cout<<endl;
  }
}

int main(){
  int n=4;
  V=std::vector<std::vector<pair<int,int>> >(n);

  edg(1,0,7); edg(0,2,5);
  edg(1,3,10); edg(2,3,15); edg(0,3,12);

  disp(V);

  std::set<int> vis;
  std::vector<int> dist(n,INT_MAX);

  dist[0]=0;

  while(vis.size()!=n){
    int sel,min=INT_MAX;

    rep(n){
      if(dist[i]<min & vis.find(i)==vis.end() ){
        sel=i; min=dist[i];
      }
    }
    vis.insert(sel);

    tr1(V[sel]){
      dist[it->first]=std::min(dist[it->first], dist[sel]+(it->second) ) ;
    }

  }

  tr1(dist)cout<<*it<<" ";
  cout<<endl;

}
