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

int flow=0;
// int bfs(int pos,int dest,set<int> vis=set<int>(),int min=INT_MAX,std::vector<std::vector<pair<int,int>> > &v=V){
//   if(pos==dest){
//     flow+=min;
//     return min;
//   }
//   for(int i=0;i<v[pos].size();i++){
//     if(vis.find(v[pos][i].first)!=vis.end() )continue;
//     if(v[pos][i].second<min )min=v[pos][i].second;
//     vis.insert(v[pos][i].first);
//
//     // v[pos][i].second-=
//     bfs(v[pos][i].first,dest,vis);
//
//   }
//   return 0;
// }

int bfs(int pos,int dest,std::vector<int> min,set<int> vis=set<int>()){
  // if(pos==dest)return min[pos];

}


int main(){
  int n=4;
  V=std::vector<std::vector<pair<int,int>> >(n);

  edg(1,0,7); edg(0,2,5);
  edg(1,3,10); edg(2,3,15); edg(0,3,12);

  disp(V);

  // set<int> vis; vis.insert(0);
  // bfs(0,3,vis);
  // cout<<flow<<endl;
}
