#include <bits/stdc++.h>
using namespace std;

# define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++ )
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

void edg(std::vector<pair<int,int> > v[],int i,int j,int wt){
  v[i].push_back( make_pair(j,wt) );
  v[j].push_back( make_pair(i,wt) );
}

int main(){
  int V=5;
  // WEIGHTED GRAPH:
  std::vector<pair<int,int>> v[V];
  edg(v,0,1,5); edg(v,1,4,7); edg(v,4,2,3);
  edg(v,0,4,1); edg(v,2,3,10); edg(v,3,4,4);

  for(int i=0;i<V;i++){
    cout<<i<<" : ";
    tr1(v[i])cout<<"("<<it->first<<"-"<<it->second<<") ";
    cout<<endl;
  }

}
