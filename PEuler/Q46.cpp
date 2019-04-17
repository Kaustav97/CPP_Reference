#include <bits/stdc++.h>
using namespace std;

int main(){
  std::vector<bool> nums(100000,1);
  std::vector<int> prm;

  for(int i=2;i<nums.size();){
    prm.push_back(i);
    for(int j=2;(i*j)<nums.size();j++)nums[i*j]=0;
    i++;
    while(nums[i]==0)i++;
  }

  // for(int x:prm)cout<<x<<" ";
  for(int num=33;num<100000;num++){
    int pos = upper_bound(prm.begin(),prm.end(),num)-prm.begin()-1;
    bool flg=0;
    for(int i=0;i<=pos;i++){
      double res = (num-prm[i])/2;
      res= sqrt(res);
      if(res-((int)res)==0)flg=1;
    }
    if(!flg)cout<<num<<endl;
  }
  cout<<"done"<<endl;
}
