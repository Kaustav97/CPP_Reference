#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <string>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

string bin(int a){
  string ans;
  for(int i= floor(log2(a));i>=0;i-- ){
    if(a & (1<<i) )ans.push_back('1');
    else ans.push_back('0');
  }
  return ans;
}

int rotright(int num,int tim){
  int mx=floor(log2(num));

  rep(tim){
    bool flg=0;
    if((num & 1)==1)flg=1;
    num=num>>1;
    if(flg) num=( num | (1<< mx ) );
    cout<<num<<": ";bin(num);
  }
}



int main(){
  int n1=38,n2=45,n3=41;
  std::vector<int> v={38,45,41,89,66,72};


  tr1(v)cout<<*it<<" ";
  cout<<endl;

  int calls=0;

  rep(3){

    // ONE ROTATION :
    for(int i=0;i<v.size();i++){
      // int res=0;
      for(int j=0;j<v.size();j++){
        calls++;
        if(i==j)continue;
        else v[i]=v[i]^v[j];
      }
      // v[i]=res;
    }
    for(int j=1;j<v.size();j++)v[0]=v[0]^v[j];

  }

  tr1(v)cout<<*it<<" ";
  cout<<endl<<calls;
}
