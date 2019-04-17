#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int main(){
  int rw=4,cl=4;


  std::vector<std::vector<int> > grd={
    {9, 6, 5, 2},
    {8, 7, 6, 5},
    {7, 3, 1, 6},
    {1, 1, 1, 7},
  };

  grd.insert(grd.begin(),std::vector<int>(cl+1,0) );
  rep(rw)grd[i+1].insert(grd[i+1].begin(),0 );

  // std::vector<std::vector<int> > dp=grd;
  std::vector<std::vector<int> > dp(rw+1,std::vector<int>(cl+1,1));

  // tr1(grd){
  //   rep((*it).size() )  {
  //     if((*it)[i]<10) cout<<(*it)[i]<<"  ";
  //     else cout<<(*it)[i]<<" ";
  //   }
  //   cout<<endl;
  // }

  // cout<<" ----------------- "<<endl;

  int mx=0;

  for(int i=1;i<=rw;i++){
    for(int j=1;j<=cl;j++){
      int up=1,lft=1;
      if( abs(grd[i-1][j]-grd[i][j]) ==1 )up=dp[i-1][j]+1;
      if( abs(grd[i][j-1]-grd[i][j]) ==1 )lft=dp[i][j-1]+1;
      if(up+lft>2)dp[i][j]=max(lft,up);
      if(dp[i][j]>mx) mx=dp[i][j];
    }
  }

  cout<<mx<<endl;

  tr1(dp){
    rep((*it).size() )  {
      if((*it)[i]<10) cout<<(*it)[i]<<"  ";
      else cout<<(*it)[i]<<" ";
    }
    cout<<endl;
  }


}
