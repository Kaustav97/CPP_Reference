#include <iostream>
#include <vector>

using namespace std;

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)

void highpath(std::vector<std::vector<int> > &v,std::vector<int> maxpath){
  // static std::vector<int> maxpath=v[0];

  std::vector<int> newmax;
  if(v[0].size()==1)newmax=maxpath;

  int flag=0;

  if(v[0].size()>=2){
    newmax.push_back(v[0][0]+maxpath[0]);
    for(int i=1;i<v[0].size()-1;i++){
      newmax.push_back(max(v[0][i]+maxpath[i],v[0][i]+maxpath[i-1] ) );
      // flag=1;
    }
    newmax.push_back( v[0].back()+maxpath.back() );
    flag=1;
  }

  if(flag)maxpath=newmax;

  // tr(maxpath)cout<<*it<<" ";
  // cout<<'\t'<<v.size()<<endl;

  v.erase(v.begin());

  if(v.size()==0){
    // find M
    int opt=maxpath[0];
    tr(maxpath){
      // cout<<*it<<" ";
      if((*it)>opt)opt=(*it);
    }
    std::vector<int> ans;
    ans.push_back(opt);
    v.push_back(ans);
    return;
  }
  else highpath(v,maxpath);
}

int main(){
  // int tst;cin>>tst;
  // for(int i=0;i<tst;i++){
    // int n;cin>>n;
    std::vector<std::vector<int> > pyr;

    // for(int i=0;i<n;i++){
    //   std::vector<int> row(i+1);
    //   for(int j=0;j<=i;j++){
    //     cin>>row[j];
    //   }
    //   pyr.push_back(row);
    // }

    pyr.push_back({1});
    pyr.push_back({1,2});     [1]
    pyr.push_back({4,1,2});   [2,3]
    pyr.push_back({2,3,1,1});  [6  4  5]

    // tr(pyr){
    //   for(int i=0;i<(*it).size();i++)cout<<(*it)[i]<<" ";
    //   cout<<endl;
    // }

    highpath(pyr,pyr[0]);
    cout<<pyr[0][0]<<endl;
  // }
}
