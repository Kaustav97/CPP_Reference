#include <bits/stdc++.h>

using namespace std;
#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr1(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second

int main(){
  int tst; cin>>tst;
  while(tst--){
    string s1,s2;
    cin>>s1>>s2;
    while(s2.length()>s1.length()){
      if(s2.back()=='K'){
        s2.pop_back();
        reverse(s2.begin(),s2.end());
      }
      else{
        s2.pop_back();
      }
    }
    if(s1!=s2)cout<<"no"<<endl;
    else cout<<"yes"<<endl;

  }
}
