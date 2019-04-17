#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int ways=0,calls=0;
void putcaps(std::vector<std::vector<int> > &v,set<int> tak=set<int>(),int ans=0,int pos=0){

  if(ans==v.size()){
    ways++;
    return;
  }
  calls++;
  for(int i=0;i<v[pos].size();i++){
    if(tak.find(v[pos][i])==tak.end() ){

      ans++;
      tak.insert(v[pos][i]);
      putcaps(v,tak,ans,pos+1);

      ans--;
      tak.erase(v[pos][i]);
    }

  }

}

int main(){

  std::vector<std::vector<int> > v={
    {5,100,1,20,35,40},
    {2,7,9,15,33,55,67},
    {5,100,99,85,17,12,37,44},
    {11,22,33,46,57,91,92},
    {13,27,29,81,83,75,99,88},
  };

  putcaps(v);
  cout<<ways<<endl<<calls<<" calls"<<endl;

}
