#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)


int main(){
  std::vector<int> poss={1,7,12,20};

  int max=poss[0];
  tr1(poss){
    if(*it>max)max=*it;
  }
  int len=max+1,qry=;
  std::vector<long long> ways,chk;
  ways.push_back(1);

  int pos=1;
  while(pos<=max){
    long long num=0;
    tr1(poss){
      if(pos-(*it)>=0)num+=ways[pos-(*it)];
    }
    ways.push_back(num);
    pos++;
  }
  std::reverse(ways.begin(),ways.end());

  tr1(ways)cout<<*it<<" ";
  cout<<endl;

  while(pos<(qry+1)){
    ways.erase(ways.end()-1);ways.insert(ways.begin(),0);
    long long num=0;
    tr1(poss)num+=ways[*it];
    ways[0]=num;
    pos++;
  }

  if(qry<=max)cout<<qry<<" - "<<ways[max-qry]<<endl;
  else cout<<qry<<" - "<<ways[0]<<endl;

}
