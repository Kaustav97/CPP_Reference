#include <bits/stdc++.h>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long


int buildst(std::vector<int> &v,int *st,int bg,int end,int tpos=0){
  if(end==bg){
    st[tpos]=v[bg];
    return v[bg];
  }
  int mid=(bg+end)/2;
  st[tpos]=buildst(v,st,bg,mid,(2*tpos)+1) + buildst(v,st,mid+1,end,(2*tpos)+2);
  return st[tpos];
}

int ans=0;
void rngsum(int *st,int tpos,int qs,int qe,int ts,int te){
  cout<<ts<<" to "<<te;

  // part of range
  if(qs<=ts && qe>=te){
    ans+=st[tpos];
    cout<<" --- ADDED "<<endl;
    return;
  }
  // outside
  else if(qs>te || qe<ts){
    cout<<endl;
    return;
  }

  cout<<endl;
  // overlaps
  rngsum(st,(2*tpos)+1,qs,qe,ts,(te+ts)/2);
  rngsum(st,(2*tpos)+2,qs,qe,(te+ts)/2+1,te);
}

void update(int *st,int ind,int diff,int ts,int te,int tpos=0){
  // value at position ind updated
  // index outside range
  if(ind<ts || ind>te)return;

  // present in range, then update
  st[tpos]+= diff;
  if(te-ts>1){
    int mid=(te+ts)/2;
    update(st,ind,diff,ts,mid,(2*tpos)+1);
    update(st,ind,diff,mid+1,te,(2*tpos)+2);
  }
}

int main(){
  std::vector<int> v={1,3,8,5,7,9};
  int tsz=pow(2, ceil(log2(v.size()))+1 );

  int st[tsz]={0};
  buildst(v,st,0,v.size()-1);

  rep(tsz)cout<<st[i]<<" ";
  cout<<endl;

  update(st,5,10,0,5);

  rep(tsz)cout<<st[i]<<" ";
  cout<<endl;

  rngsum()

}
