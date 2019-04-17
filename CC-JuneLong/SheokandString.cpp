#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int pref(string &a,string &b){
  int sz=min(a.size(),b.size());
  int com=0;
  rep(sz){
    if(a[i]==b[i])com++;
    else break;
  }
  return com;
}

int main(){
  int n; cin>>n;
  vector<string> s(n);

  // s.push_back("abcd");s.push_back("abce");
  // s.push_back("abcdex");s.push_back("abcde");

  rep(n){
    cin>>s[i];
  }

  int q; cin>>q;
  rep(q){
    int r;string p;
    cin>>r>>p;

    int max=0;
    set<string> chk;

    std::vector<string>::iterator it = s.begin();

    for(it;it!=s.begin()+r;it++){
      int curr=pref(*it,p);
      if(curr>max){
        max=curr;
        chk.clear();
        chk.insert(*it);
      }
      if(curr==max){
        chk.insert(*it);
      }
    }
    cout<<*(chk.begin())<<endl;
  }
}
