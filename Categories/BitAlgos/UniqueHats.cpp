#include <bits/stdc++.h>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second

int calls=0;int rcalls=0;
std::vector<int> ans;
void allsub(std::vector<int> &v,int pos=0){
  if(pos==v.size()){
    tr1(ans)cout<<*it<<" ";
    cout<<endl;
    return;
  }
  rcalls++;
  // leave
  allsub(v,pos+1);

  // take
  ans.push_back(v[pos]);
  allsub(v,pos+1);
  ans.pop_back();
}

int main(){
  std::vector<int> v={3,15,25,18,9,17,5};
  allsub(v);
  cout<<rcalls<<endl;
}
