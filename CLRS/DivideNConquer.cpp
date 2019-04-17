#include <bits/stdc++.h>
using namespace std;

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int lrg(const std::vector<int> &v,int lw,int hg){
  cout<<lw<<" to "<<hg<<endl;
  if(hg-lw<=1)return max(v[lw],v[hg]);
  int mid=(lw+hg)/2;
  return max( lrg(v,lw,mid),lrg(v,mid+1,hg) );
}

int main(){
  std::vector<int> arr={4,19,56,5,10,11,7,33,17};
  cout<<lrg(arr,0,arr.size()-1)<<endl;
}
