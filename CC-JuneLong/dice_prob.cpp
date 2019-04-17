#include <vector>
#include <iostream>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int main(){
  int t;cin>>t;
  rep(t){
    int n,a,b;
    cin>>n>>a>>b;
    std::vector<int> v(n);
    rep(n)cin>>v[i];

    double fa=0,fb=0;
    tr1(v){
      if(*it==a)fa++;
      if(*it==b)fb++;
    }
    // cout<<fa<<" "<<fb;
    cout<<(fa/n*1.0)*(fb/n*1.0)<<endl;
  }
}
