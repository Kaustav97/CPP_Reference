#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

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

// QUESTION: ways to assign unique cap to every person: https://www.geeksforgeeks.org/bitmasking-and-dynamic-programming-set-1-count-ways-to-assign-unique-cap-to-every-person/

// Recursive Approach
int calls=0; int ways=0;
void all_ways(std::vector<std::vector<int>> v,std::vector<int> ans){
  if(v.empty()){

    std::unordered_map<int,int> rec(ans.size());
    tr1(ans)rec[*it]++;
    tr1(rec)if(it->second>1)return;

    // tr1(ans)cout<<*it<<" ";
    // cout<<endl;
    ways++;
    return;
  }
  else{
    std::vector<int> tmp=v[0];
    for(int i=0;i<v[0].size();i++){
      calls++;
      ans.push_back(v[0][i]);
      v.erase(v.begin());
      all_ways(v,ans);
      ans.pop_back();
      v.insert(v.begin(),tmp);
    }
  }

}

int main(){
  int n=5;
  std::vector<std::vector<int> > caps(n);
  caps[0]={5,100,1,20,35,40};
  caps[1]={2,7,9,15,33,55,67};
  caps[2]={5,100,99,85,17,12,37,44};
  caps[3]={11,22,33,46,57,91,92};
  caps[4]={13,27,29,81,83,75,99,88};

  std::vector<int> ans;
  all_ways(caps,ans);
  cout<<ways<<" ways"<<endl;
  cout<<calls<<" calls"<<endl;



}
