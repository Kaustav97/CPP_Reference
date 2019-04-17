#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)

void poss(std::vector<int> &v,int orgsize){
  int sum=0;
  for(int i=0;i<orgsize;i++){
    sum+=v[0];
    v.push_back(sum);
    v.erase(v.begin());
  }
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3){
  std::reverse(h1.begin(),h1.end());
  std::reverse(h2.begin(),h2.end());
  std::reverse(h3.begin(),h3.end());

  poss(h1,h1.size());
  poss(h2,h2.size());
  poss(h3,h3.size());

  // tr(h1)cout<<*it<<" ";
  // cout<<endl;
  // tr(h2)cout<<*it<<" ";
  // cout<<endl;
  // tr(h3)cout<<*it<<" ";
  // cout<<endl;

  std::vector<int> res(min(h1.size(),min(h2.size(),h3.size()) ) );
  set_intersection(h1.begin(),h1.end(),h2.begin(),h2.end(),res.begin());

  tr(res)cout<<*it<<" ";
  cout<<endl;
  std::vector<int> res2(min(res.size(),h2.size()) );
  set_intersection(h3.begin(),h3.end(),res.begin(),res.end(),res2.begin());

  tr(res2)cout<<*it<<" ";
  cout<<endl;

  int ans=res2[0];

  tr(res2){
    if(*it>ans)ans=*it;
  }
  return ans;
}

int main(){
  std::vector<int> v1={3,2,1,1,1};
  std::vector<int> v2={4,3,2};
  std::vector<int> v3={1,1,4,1};

  int ans=equalStacks(v1,v2,v3);

  // cout<<ans;

  // tr(v){
  //   cout<<*it<<" ";
  // }
}
