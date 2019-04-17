#include <bits/stdc++.h>
using namespace std;

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

// find maximum crossing sum
int max_cross(const std::vector<int> &v,int lw,int hg){
  int mid=(lw+hg)/2;
  int lsum=-(INT_MAX);
  int sum=0;
  for(int i=mid;i>=lw;i--){
    sum+=v[i];
    if(sum>lsum)lsum=sum;
  }
  int rsum=-(INT_MAX);
  sum=0;
  for(int i=mid+1;i<hg;i++){
    sum+=v[i];
    if(sum>rsum)rsum=sum;
  }
  return lsum+rsum;
}

// find overall maximum contiguous sum
int max_sum(const std::vector<int> &v,int lw,int hg){
  cout<<lw<<" , "<<hg<<endl;
  int mid=(lw+hg)/2;
  if(hg-lw<=1)return v[mid];

  // left
  int lft=max_sum(v,lw,mid);

  // right
  int rgt=max_sum(v,mid+1,hg);

  // crossing

  int crs=max_cross(v,lw,hg);
  return max(max(lft,rgt),crs);
}

int main(){
  std::vector<int> stk={100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};

  int tmp=stk[0];
  stk[0]=0;
  for(int i=1;i<stk.size();i++){
    int nv=stk[i]-tmp;
    tmp=stk[i];
    stk[i]=nv;
  }

  tr(stk)cout<<*it<<" ";
  cout<<endl;

  cout<<max_sum(stk,0,stk.size()-1)<<endl;
}
