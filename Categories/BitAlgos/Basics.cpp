#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

// MASK OPERATIONS:-
  // bit(i,mask) return ith bit of mask
  // count(mask) count # of set bits
  // first(mask) lowest set bits
  // set(i,mask) set ith bit  ------------ ( mask OR (1<<i) )
  // unset(i,mask) unset ith bit  -------- ( mask AND !(1<<i) )
  // check(i,mask) boolean, ith bit  ----- ( mask AND (1<<i) )

// USEFUL INFO:
  // use __builtin_popcount(n) to count # of set bits in n O(1) time!!

void printbin(int num){
  for(int i=0;i<(1<<num) ;i++){
    for(int j=num-1;j>=0;j--){
      if(i & (1<<j))cout<<"1";
      else cout<<"0";
    }
    cout<<" --- "<<i<<endl;
  }
}

int iter_calls=0,rec_calls=0;

// Bitwise :- O(n2^n )
void sets(std::vector<int> &v){
  for(int i=0;i<(1<<(v.size())) ;i++ ){
    for(int j=v.size()-1;j>=0;j--){
      iter_calls++;
      // if(i & (1<<j) )cout<<v[j]<<" ";
      // else continue;
    }
    // cout<<endl;
  }
}

// Recursion :- O( 2^(n+1) )    MORE EFFICIENT ??
void allsubsets(std::vector<int> &v,int pos,std::vector<int> ans){
  rec_calls++;
  if(pos==v.size()){
    // tr1(ans)cout<<*it<<" ";
    // cout<<endl;
    return;
  }
  // leave out
  allsubsets(v,pos+1,ans);

  // include
  ans.push_back(v[pos]);
  allsubsets(v,pos+1,ans);
}


int main(){
  // int n=4;
  // printbin(6);
  std::vector<int> v={11,13,8,9,18,15,12};
  sets(v);
  allsubsets(v,0,std::vector<int>());
  cout<<"recursion: "<<rec_calls<<endl<<"iteration:  "<<iter_calls<<endl;
}
