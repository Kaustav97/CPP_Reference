#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int twoStacks(int x,int score, vector<int> &a, vector<int> &b){
  // 0 -> a , 1-> b
  int rem_st,rem;

  // cout<<a[0]<<"\t"<<b[0]<<'\t';

  if(a[0]<b[0]){rem_st=0;rem=a[0];}
  else {rem_st=1;rem=b[0];}

  // cout<<rem_st;

  if(x-rem<0)return score;

  if(rem_st==0){
    // cout<<"  Rem from A"<<endl;
    // score++;
    a.erase(a.begin());
    twoStacks(x-rem,score+1,a,b);
  }
  else if(rem_st==1){
    // cout<<"  Rem from B"<<endl;
    // score++;
    b.erase(b.begin());
    twoStacks(x-rem,score+1,a,b);
  }

}

int main(){
  std::vector<int> v1={4,2,4,6,1};
  std::vector<int> v2={2,1,8,5};
  int ans=twoStacks(10,0,v1,v2);
  cout<<ans;
}
