#include <iostream>
#include <vector>

using namespace std;

#define tr2(cont,it) for(it;it!=cont.end();it++)
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)

int ways=0;

void findways(int amt,std::vector<int> &coins){
  // tr1(coins)cout<<*it<<" ";
  // cout<<'\t'<<amt<<endl;

  if(coins.size()==0)return;
  if(amt<0)return;
  if(amt==0){ways++;return;}

  int c=coins[0];

  // include multiple
  findways(amt-c,coins);

  // include
  findways(amt-c,coins);

  coins.erase(coins.begin());

  findways(amt-c,coins);

  // don't include
  findways(amt,coins);

  cout<<ways<<endl;
  cout<<"here";

  return;
}

int main(){
  // int num,amt;
  // cin>>amt>>num;

  // std::vector<int> coins(num);
  // for(int i=0;i<num;i++)cin>>coins[i];
  // cout<<"HI";

  std::vector<int> coins={1,2,3};
  int amt=4;

  findways(amt,coins);
  cout<<"ans: "<<ways<<endl;
}
