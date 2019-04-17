#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
  std::vector<bool> nums(1000000,1);
  std::vector<int> prm;

  for(int i=2;i<nums.size();){
    prm.push_back(i);
    for(int j=2;(i*j)<nums.size();j++)nums[i*j]=0;
    i++;
    while(nums[i]==0)i++;
  }
  // for(int i=0;i<50;i++)cout<<prm[i]<<" ";
  std::vector<ll> cum;
  cum.push_back(2);
  for(int i=1;i<prm.size();i++){
    cum.push_back(cum[i-1]+prm[i]);
    // if(cum[i]-cum[max(0,i-21)]>1000000 )break;
  }
  // cout<<cum[cum.size()-1];
  int pos= upper_bound(cum.begin(),cum.end(),953)-cum.begin();
  int mx=0;
  for(int i=pos;i<cum.size();i++){
    for(int j=i-mx-1;j>=0;j--){
      if(cum[i]-cum[j]<1000000 && binary_search(prm.begin(),prm.end(),cum[i]-cum[j])){
        mx=i-j;
        cout<<(i-j)<<" - "<<cum[i]-cum[j]<<endl;
      }
    }
  }



}
