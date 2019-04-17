#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

// QUESTION: https://www.geeksforgeeks.org/game-theory-choice-area/

int A,B;

std::set<pair<int,std::vector<pair<char,pair<int,int>>>> > poss;

void play(int a,int b,int time,char cr,std::vector<pair<char,pair<int,int> > > ans){
  if(a<0 | b<0){
    // cout<<time-1<<" - ";
    ans.pop_back();
    poss.insert(make_pair(time-1,ans));
    return;
  }
  // tr1(ans)cout<<*it<<" ";
  // cout<<endl;

  std::vector<pair<char,pair<int,int> > > tmp=ans;

  // X:
  if(cr!='x'){
    ans=tmp;
    ans.push_back(make_pair('X',make_pair(a+3,b+2)));
    play(a+3,b+2,time+1,'x',ans);
  }

  // Y:
  if(cr!='y'){
    ans=tmp;
    ans.push_back(make_pair('Y',make_pair(a-5,b-10)));
    play(a-5,b-10,time+1,'y',ans);
  }
  // Z:
  if(cr!='z'){
    ans=tmp;
    ans.push_back(make_pair('Z',make_pair(a-20,b+5)));
    play(a-20,b+5,time+1,'z',ans);
  }
  return;

}

int main(){
  A=20,B=8;
  std::vector<pair<char,pair<int,int> > > ans;

  play(A,B,0,'i',ans);

  std::set<pair<int,std::vector<pair<char,pair<int,int>>> > >::iterator it2=poss.begin();
  for(it2;it2!=poss.end();it2++){
    cout<<it2->first<<" : ";
    tr1(it2->second){
      cout<<it->first<<"("<<it->second.first<<","<<it->second.second<<") ";
    }
    cout<<endl<<endl;
  }
}
