#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

/*
Question:
Find number of moves to convert one binary number A to another B
by using the following move any number of times:
 1.arbitrarily permute bits in A to get S
 2.add 1, S=S+1
 3.replce A by S
Output number of moves if possible, otherwise -1;
*/

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)


//  0010 to 1000 -- 6 moves

/*
0 pad to equal lengths
Same:
  last 2 of b:
   ..00- make num of 1s equal. match till last 1, (posdiff+1) moves
   01- change to one less 1
   10- done
   ..11- match till last 0 with one less 1m then 1 move

x  Just 1: (posdiff+1) moves
x  >1: match higher bits, till 1 leftm compare with 2

Less:
  add diff to moves
More:
  one move required to make equal

Cases:
 101010 to 011111
 10110010 to 11100110
 10110010 to 01111
   0111
*/

int tobin(long a,std::vector<bool> &ans){
  if(a==1|a==0){
    ans.push_back(a%2);
    std::reverse(ans.begin(),ans.end());
    return 0;
  }
  bool rem=a%2;
  ans.push_back(rem);
  tobin(a/2,ans);
}
int todec(std::vector<bool> v){
  int ans=0,p=0;
  std::reverse(v.begin(),v.end());
  tr1(v){
    ans+=(*it)*pow(2,p++);
  }
  return ans;
}

void make_same(std::vector<bool> &a,std::vector<bool> &b){
  int diff;
  if(a.size()>b.size())diff=a.size()-b.size();
  else diff=b.size()-a.size();

  if(a.size()>b.size()){
    b.insert(b.begin(),diff,0);
  }
  else if(a.size()<b.size()){
    a.insert(a.begin(),diff,0);
  }

}


int main(){
  // std::vector<bool> a={1,0,1,1,0,0,1,0};
  // std::vector<bool> b={0,0,1,1,1,1,0,0};

  std::vector<bool> a={0,0,0,0,0,1};
  std::vector<bool> b={0,0,0,1,0,0,0,0};
  lst-diff+2+1
  // 111000

  // 110101 to 0010000

  make_same(a,b);

  tr1(a)cout<<*it;cout<<endl;
  tr1(b)cout<<*it;cout<<endl;

  if(a==b){cout<<0;return 0;}
  else if(todec(b)==0 | todec(b)==1){cout<<-1;return 0;}

  // count 1s
  int a1=0,b1=0,moves=0;
  int len=a.size()-1;

  tr1(a)a1+=*it;
  tr1(b)b1+=*it;
  int diff=abs(a1-b1);

  // cout<<a1<<" "<<b1<<endl;

  // if(a1<b1)moves+=(b1-a1);
  // if(a1>b1)moves++;

  // Same number of 1s

  bool bl=b[len],bsl=b[len-1];

  if(bsl==0 & bl==0){
    if(a1<b1)moves+=(b1-a1);
    if(a1>b1)moves++;

    // one move
    int pos=0;
    tr1(b){
      if(pos==b1-1)break;
      if((*it)==1)pos++;
      b.erase(b.begin());it--;
    }

    std::reverse(b.begin(),b.end());
    int lst=0;
    tr1(b){
      lst++;
      if(*it==1)break;
    }
    if(lst==diff+2);
    else moves+=lst-(diff+2)+1;
    // if(2+(abs(a1-b1))==lst & a1>b1)moves++;
    // else moves+=lst-2+1;
  }

  if(bsl==0 & bl==1){
    if(a1==b1-1)moves++;
    else{
      if(a1<b1)moves+=(b1-a1);
      if(a1>b1)moves+=2;
    }
  }
  cout<<moves;
  return 0;

}
