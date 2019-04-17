#include <bits/stdc++.h>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second

std::vector<int> seg,v;

int build(int pos=0,int lw=0,int hg=v.size()-1){
  int mid=(lw+hg)/2;
  if(hg==lw){
    seg[pos]=v[lw];
    return v[lw];
  }
  seg[pos]= build((2*pos)+1,lw,mid) + build((2*pos)+2,mid+1,hg);
  return seg[pos];
}

int query(int qs,int qe,int pos=0,int lw=0,int hg=v.size()-1){
  // cout<<lw<<" , "<<hg<<endl;
  int mid=(lw+hg)/2;
  if(qe<lw | qs>hg)return 0;
  else if(qs<=lw && qe>=hg){
    // ans+=seg[pos];
    return seg[pos];
  }
  if(qs>=lw | qe<=hg){
    return query(qs,qe,(2*pos)+1,lw,mid) + query(qs,qe,(2*pos)+2,mid+1,hg);
  }
}

void update(int pos,int diff,int sp=0,int lw=0,int hg=v.size()-1 ){
  int mid=(lw+hg)/2;
  // cout<<lw<<" "<<hg<<endl;
  if(pos<lw | pos>hg)return;
  if(pos>=lw){
    seg[sp]+=diff;
    if(lw==hg)return;
    update(pos,diff,(2*sp)+1,lw,mid);
    update(pos,diff,(2*sp)+2,mid+1,hg);
  }
}

void incr(int qs,int qe,int lw=0,int hg=v.size()-1,int pos=0){
  int mid=(lw+hg)/2;
  // cout<<lw<<" "<<hg<<endl;
  if(qs>hg | qe<lw) return;

  // completely inside
  if(qs>=lw && qe<=hg){
    seg[pos]+=(qe-qs+1);
    // cout<<" -- here1"<<endl;
    if(lw==hg)return;
    incr(qs,qe,lw,mid,(2*pos)+1);
    incr(qs,qe,mid+1,hg,(2*pos)+2);
  }

  else if(qs<=lw && qe>=hg){
    seg[pos]+=(hg-lw)+1;
    if(lw==hg)return;
    incr(qs,qe,lw,mid,(2*pos)+1);
    incr(qs,qe,mid+1,hg,(2*pos)+2);
  }

  // left partial
  else if(qe>=lw && qs<lw){
    seg[pos]+=(qe-lw+1);
    // cout<<" -- here2"<<endl;
    if(lw==hg)return;
    incr(qs,qe,lw,mid,(2*pos)+1);
    incr(qs,qe,mid+1,hg,(2*pos)+2);
  }

  // right partial
  else if(qs<=hg && qe>hg){
    seg[pos]+=(hg-qs+1);
    // cout<<" -- here3"<<endl;
    if(lw==hg)return;
    incr(qs,qe,lw,mid,(2*pos)+1);
    incr(qs,qe,mid+1,hg,(2*pos)+2);
  }
}

int ans=0;
int mul3(int qs,int qe,int pos=0,int lw=0,int hg=v.size()-1){
  // cout<<lw<<" , "<<hg<<endl;
  int mid=(lw+hg)/2;
  if(qe<lw | qs>hg)return 0;
  else if(qs<=lw && qe>=hg){
    if(lw==hg){if(seg[pos]%3==0)ans++; return 0;}
    mul3(qs,qe,(2*pos)+1,lw,mid);
    mul3(qs,qe,(2*pos)+2,mid+1,hg);
    // return (seg[pos]%3==0);
  }
  if(qs>=lw | qe<=hg){
    mul3(qs,qe,(2*pos)+1,lw,mid);
    mul3(qs,qe,(2*pos)+2,mid+1,hg);
  }
}

int main(){
  // v={3,13,7,19,21,5,6};
  v={0,0,0,0,0,0,0};
  seg=std::vector<int>(pow(2,ceil(log2(v.size() )+1) ) );
  build();

  incr(3,6);
  incr(2,4);
  // incr(1,5);
  mul3(0,6);
  cout<<ans<<endl;

  tr1(seg)cout<<*it<<" ";

  // query(2,5,0,v.size()-1);
  // cout<<ans<<endl;
}
