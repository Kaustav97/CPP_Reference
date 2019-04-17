#include <bits/stdc++.h>
using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define fs first
#define sc second

std::vector<std::vector<pair<int,int>> > V;

void edg(int fr,int to,int wt){
  V[fr].push_back(make_pair(to,wt));
  V[to].push_back(make_pair(fr,wt));
}

void djikstra(int pos,int dest,std::vector<int> &dst,set<int> vis,std::vector<std::vector<pair<int,int>> > v=V){
  if(vis.size()==v.size())return;
  cout<<pos<<endl;
  if(vis.find(pos)==vis.end()){
    for(int i=0;i<v[pos].size();i++){
      dst[v[pos][i].fs]=min(dst[v[pos][i].fs],dst[pos]+v[pos][i].sc );
    }
    vis.insert(pos);
    djikstra(pos+1,dest,dst,vis);
  }

}

int main(){
  int n=4;
  V=std::vector<std::vector<pair<int,int>> >(n);
  edg(0,1,5); edg(1,3,-7); edg(0,3,10);
  edg(0,2,5); edg(2,3,15);

  int pos=0;
  tr1(V){
    cout<<(pos++)<<" : ";
    rep((*it).size())cout<<"("<<(*it)[i].fs<<","<<(*it)[i].sc<<") ";
    cout<<endl;
  }
  set<int> vis;
  std::vector<int> mindist(n,INT_MAX);
  mindist[0]=0;
  djikstra(0,3,mindist,vis);
  tr1(mindist)cout<<*it<<" ";
}
