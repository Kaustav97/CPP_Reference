#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int moves(string &a,string &b,int ans){
  int len=a.size()-1;
  if(a==b)return ans;
  if(a[len]==b[len]){
    a.pop_back();b.pop_back();
    moves(a,b,ans);
  }
  else{
    cout<<a<<", "<<b<<endl;
    int nans=ans;
    while(a[len]!=b[len]){
      char mv=a[a.size()-1];
      a.pop_back();
      a.insert(0,1,mv);
      nans++;
      continue;
    }
    moves(a,b,nans);
  }
}

int main(){
  string a="EACBD",b="EABCD";
  // Check same length
  map<char,int> s1,s2;
  rep(a.size()){
    s1[a[i]]++;
    s2[b[i]]++;
  }

  if(std::equal(s1.begin(),s1.end(),s2.begin())){
    cout<<moves(a,b,0);
  }

}
