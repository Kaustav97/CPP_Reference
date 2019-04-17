#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

// int rec_calls=0;
int tot_calls=0;

int num=0;

//  PERMUTATIONS USING BITMASKING !!
void permute(std::vector<int> &v,std::vector<int> ans,int pos=0,int rec=0){
  if(rec==(1<<v.size() )-1){
    tr1(ans)cout<<*it<<" ";
    cout<<endl;
    num++;
    return;
  }

  tot_calls++;
  for(int i=0;i<v.size();i++){
    if((rec & (1<<i))==0)ans[i]=v[pos];
    else continue;
    permute(v,ans,pos+1,(rec | (1<<i) ) );
  }

}

void allsubsets(std::vector<int> &v,int &sz,int pos=0,std::vector<int> ans=std::vector<int>() ){
  // rec_calls++;
  if(pos==v.size()){
    // if(ans.size()!=sz)return;

    // tr1(ans)cout<<*it<<" ";
    // cout<<endl; num++;

    // ans vector is a unique SELECTION, we then PERMUTE each selection
    permute(ans,std::vector<int>(ans.size()) );
    // cout<<"--------------"<<endl;
    cout<<endl;
    return;
  }

  tot_calls++;

  // leave out
  allsubsets(v,sz,pos+1,ans);

  // include
  ans.push_back(v[pos]);
  allsubsets(v,sz,pos+1,ans);
}

int main(){
  int sz=3;
  std::vector<int> v={10, 20, 30, 40, 50};

  // allsubsets(v,sz);
  permute(v,std::vector<int>(v.size()) );


  cout<<tot_calls<<" calls for "<<num<<" results"<<endl;

}
