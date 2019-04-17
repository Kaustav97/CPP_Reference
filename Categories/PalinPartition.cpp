#include <bits/stdc++.h>
using namespace std;

#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++ )
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

bool check(string str){
  int pos=0;
  std::vector<string> v;
  while(str.size()>0){
    string tmp=str.substr(0,str.find('|')) ;
    v.push_back(tmp);
    str.erase(0,tmp.length()+1);
  }
  bool flag=1;

  tr1(v){
    // cout<<*it<<" ";
    string tmp=*it;
    string rev=tmp;
    reverse(rev.begin(),rev.end());

    if(tmp!= rev)flag=0;
  }
  return flag;
}

void splits(string str,int pos=1){
  if(pos==str.size()){
    if(check(str))cout<<str<<endl;
    return;
  }
  // don't
  splits(str,pos+1);

  // add |
  str.insert(str.begin()+pos,'|');
  splits(str,pos+2);
}

int main(){
  string str="nitin";
  splits(str);

  std::vector<std::vector<bool> > dp(str.size(),std::vector<bool>(str.size(),0 ) );

  for(int i=0;i<str.size();i++){
    for(int j=1;j<=str.size()-i;j++){
      string t1=str.substr(i,j);
      // cout<<t1<<endl;
      string rev=t1;
      reverse(rev.begin(),rev.end());
      dp[i][j-1]=(t1==rev);
    }
  }

  // tr1(dp){
  //   rep((*it).size())cout<<(*it)[i]<<" ";
  //   cout<<endl;
  // }



}
