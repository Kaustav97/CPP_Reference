#include <iostream>
#include <vector>

using namespace std;

#define tr2(cont,it) for(it;it!=cont.end();it++)
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)

int smoky(std::vector<int> &v){
  int curr=0;

  while(v.size()>2){
    std::vector<int>::iterator it=v.begin()+2,pmin=v.begin()+1;
    int min=(v[0]+v[1])%100;
    tr2(v,it){
      int ns=( (*it)+(*(it-1)) )%100;
      if (ns<min){
        min=ns;
        pmin=it;
      }
    }

    curr+=v[pmin-v.begin()-1]*v[pmin-v.begin()];
    v[pmin-v.begin()-1]=min;
    v.erase(pmin);

    // tr1(v)cout<<*it<<" ";
    // cout<<"\t | "<<curr<<endl;
  }
  curr+=(v[0]*v[1]);
  return curr;
}

int main(){
  int t;cin>>t;
  // std::vector<int> ans(t);
  for(int j=0;j<t;j++){
    int n;cin>>n;
    std::vector<int> mx(n);
    for(int i=0;i<n;i++)cin>>mx[i];
    // ans[j]=(smoky(mx));
    cout<<smoky(mx)<<endl;
    // cout<<ans[j]<<endl;
  }
  // tr1(ans)cout<<*it<<endl;
}
