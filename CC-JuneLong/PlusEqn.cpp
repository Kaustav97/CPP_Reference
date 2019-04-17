#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

// std::unordered_map<string,int> hist;
string ans;

// METHOD TO SPLIT A STRING IN STL

int eval(const string &str){
  // std::unordered_map<string,int>::iterator rep=hist.find(str);
  // if(rep!=hist.end())return hist[str];

  string del="+",token;
  int pos=0;
  int sum=0;

  string tmp=str;
  // cout<<"->"<<tmp<<endl;
  // std::string::find returns std::string::npos if not found
  while( (pos=tmp.find(del))!=std::string::npos){
    token = tmp.substr(0,pos);
    sum+=std::stoi(token);
    tmp.erase(0,pos+del.length());
  }
  sum+=std::stoi(tmp);
  // hist[str]=sum;
  return sum;
}

int search(std::string str,int tgt,int pos){
  // cout<<str<<"  "<<"--"<<pos<<"&"<<str.size()<<endl;

  if(eval(str)==tgt){ans=str;return 0;}
  if(pos==str.size())return 0;

  // leave blank
  search(str,tgt,pos+1);

  // cout<<str<<"  "<<"--"<<pos<<"&"<<str.size()<<endl;

  // place +
  if(str[pos]!='+' & str[pos-1]!='+'){
    str.insert(pos,"+");
    search(str,tgt,pos+2);
  }
  return 0;
}

int main(){
  int t;cin>>t;
  rep(t){
    // hist.clear();
    string str;int req;

    cin>>str>>req;
    search(str,req,1);
    cout<<ans<<endl;
  }
  // std::string eqn="15489001";
  // search(eqn,10549,1);
}
