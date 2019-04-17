#include <bits/stdc++.h>
using namespace std;

int main(){
  std::vector<int> den={1,2,5,10,20,50,100,200};
  int lim=200;
  std::vector<std::vector<int> > dp(den.size(),std::vector<int>(lim+1,1));

  for(int i=1;i<den.size();i++){
    for(int j=1;j<=lim;j++){
      int tgt=j+1,cn=den[i];
      if(tgt<cn)dp[i][j]=dp[i-1][j];
      else dp[i][j]=dp[i-1][j]+dp[i][j-cn];
    }
  }

  // for(std::vector<int> v:dp){
  //   for(int x:v)cout<<x<<'\t';
  //   cout<<endl;
  // }
  cout<<dp[den.size()-1][lim];


}
