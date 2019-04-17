#include <bits/stdc++.h>

using namespace std;

#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)

std::vector<int> merge(std::vector<int> &v1,std::vector<int> &v2){
  std::vector<int> ans;
  std::vector<int>::iterator it1=v1.begin(),it2=v2.begin();

  while(it1!=v1.end() && it2!=v2.end() ){
    if((*it1)<(*it2)){
      ans.push_back(*it1);
      it1++;
    }
    else{
      ans.push_back(*it2);
      it2++;
    }
  }

  if(it1==v1.end()) ans.insert(ans.end(), it2 ,v2.end() );
  else if(it2==v2.end())ans.insert(ans.end(),it1,v1.end());
  return ans;
}

std::vector<int> mrgsort(std::vector<int> v){
  if(v.size()==1)return v;

  int mid=v.size()/2;
  std::vector<int> lw(v.begin(),v.begin()+mid);
  std::vector<int> hg(v.begin()+mid,v.end());

  tr1(lw)cout<<*it<<" "; cout<<" || "; tr1(hg)cout<<*it<<" ";
  cout<<endl;

  lw=mrgsort(lw);
  hg=mrgsort(hg);
  return merge(lw,hg);
}

int main(){
  std::vector<int> v={1,6,18,7,2,3,-2,5};
  std::vector<int> ans=mrgsort(v);
  tr1(ans)cout<<*it<<" ";
}
