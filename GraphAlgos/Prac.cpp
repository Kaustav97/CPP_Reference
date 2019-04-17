#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++ )
#define rep(n) for(int i=0;i<n;i++)
int rec=0;

void subs(string &s,int pos=0,string ans=""){
  rec++;
  if(pos==s.length()){
    cout<<ans<<endl;
    return;
  }
  // leave
  subs(s,pos+1,ans);

  // take
  ans+=s[pos];
  subs(s,pos+1,ans);
}

int main(){
  string str="ABAC";
  int crep=0,crec=0;
  for(int i=0;i<pow(2,str.length());i++){
    for(int j=0;j<str.length();j++){
      if( (i & (1<<j))>0 )cout<<str[j];
      crep++;
    }
    cout<<endl;
  }
  cout<<"iter: "<<crep<<endl;

  subs(str);
  cout<<"recursion: "<<rec<<endl;
}
