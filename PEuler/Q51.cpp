#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
  std::vector<bool> nums(100000000,1);
  std::vector<int> prm;

  for(int i=2;i<nums.size();){
    prm.push_back(i);
    for(int j=2;(i*j)<nums.size();j++)nums[i*j]=0;
    i++;
    while(nums[i]==0)i++;
  }

  std::vector<int> vals={10,100,1000,100000,1000000,10000000};
  for(int n:vals){
    int lw=(upper_bound(prm.begin(),prm.end(),n) )-prm.begin();
    cout<<n<<" : "<<lw<<endl;
  }
}
