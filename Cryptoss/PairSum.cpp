#include <bits/stdc++.h>

using namespace std;
#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second

set<std::vector<int> > S;
int count=0;

void split(int q,int p,std::vector<int> v=std::vector<int>() ){
  if(q==0){
    // tr(v)cout<<*it<<" ";
    // cout<<endl;
    sort(v.begin(),v.end());
    S.insert(v);
  }
  if(q<p)return;
  else{
    for(int i=p;i<=q;i++){
      v.push_back(i);
      split(q-i,p,v);
      v.pop_back();
    }
  }
}

int main(){
  int tst; cin>>tst;
  while(tst--){
    S= set<std::vector<int> >();
    int p,q;
    cin>>q>>p;
    split(q,p);
    tr(S){
      rep((*it).size())cout<<(*it)[i]<<" ";
      cout<<endl;
    }
    cout<<S.size()*q<<endl;
  }

}
