#include <vector>
#include <iostream>
using namespace std;

#define tr(cont,it) for(it;it!=cont.end();it++)
//  1 2 3 4 5

int main(){
  int n;cin>>n;
  std::vector<int> v;
  for(int i=0;i<n;i++){
    int t;cin>>t;
    v.push_back(t);
  }
  std::vector<int>::iterator it=v.begin()+1;

  int prev=*(it-1);
  int flag=1,ans=0;
  while(flag==1){
    flag=0;
    // ONE DAY
    while(it<v.end()){
      if(*it>prev){
        flag=1;
        prev=*it;
        v.erase(it);
        it--;
      }
      it++;
    }
    if(flag==1)ans++;
    it=v.begin()+1;
    prev=*(it-1);
  }

  // it=v.begin();
  // tr(v,it){
  //   cout<<*it<<" ";
  // }
  // cout<<endl;

  cout<<ans;
}
