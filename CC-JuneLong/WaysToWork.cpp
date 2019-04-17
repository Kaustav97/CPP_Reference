#include <iostream>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int main(){
  int t;cin>>t;
  rep(t){
    int n,c;
    cin>>n>>c;
    int r=n;
    n++;
    int lst=n;
    while(n!=c){
      n=n*(lst+1);
      lst++;
    }
    rep(r)cout<<lst<<" ";cout<<endl;
  }
}
