#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int main(){
  std::vector<int> val={3,5,8,9,10,17,17,20};
  int qry=8;
  std::vector<std::vector<int> > dp(val.size(),std::vector<int>(qry+1,0));

  rep(qry+1)dp[0][i]=(i*val[0]);

  for(int i=1;i<val.size();i++){
    for(int j=1;j<=qry;j++){
      if((i+1)>j)dp[i][j]=dp[i-1][j];
      else dp[i][j]=max(dp[i-1][j],val[i]+dp[i][j-i-1]);
    }
  }
  tr1(dp){
    rep((*it).size())cout<<(*it)[i]<<" ";
    cout<<endl;
  }


}
