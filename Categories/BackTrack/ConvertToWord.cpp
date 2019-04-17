#include <bits/stdc++.h>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second

int calls=0;
void conv(string s1,string s2,int mv=0){
  calls++;
  if(s1==s2){
    // cout<<mv<<endl;
    cout<<" ------- "<<mv<<" moves --------"<<endl;
    return;
  }
  // if(s1.size()==1){}
  while(s1[0]==s2[0]){
    s1.erase(s1.begin()); s2.erase(s2.begin());
  }

  // cout<<"change "<<s1<<" to "<<s2<<endl;

  // replace
  char tmp=s1[0];
  if(s1.size()>0 && s2.size()>0){
    cout<<"change "<<s1[0]<<" to "<<s2[0]<<endl;
    char tmp=s1[0];
    s1[0]=s2[0];
    conv(s1,s2,mv+1);
    s1[0]=tmp;
  }

  // remove
  if(s1.size()>s2.size()){
    cout<<"erase "<<s1[0]<<endl;
    s1.erase(s1.begin());
    conv(s1,s2,mv+1);
    s1.insert(s1.begin(),tmp);
  }


  // append
  if(s1.size()<s2.size()){
    cout<<"add "<<s2[0]<<endl;
    s1.insert(s1.begin(),s2[0]);
    conv(s1,s2,mv+1);
  }
}

int main(){
  string s1="abcdef",s2="pqrstuv";
  conv(s1,s2);
  cout<<calls<<" CALLS"<<endl;
}
