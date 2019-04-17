#include <bits/stdc++.h>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second

std::vector<std::vector<bool> >dp;
std::vector<int> ans;

int calls=0;

void trav(std::vector<int> &v,int sum,int i,int j){
  // cout<<"at ("<<i<<","<<j<<") "<<endl;
  calls++;
  if(sum==0){
    tr1(ans)cout<<*it<<" ";
    cout<<endl;
    return;
  }

  if( (dp[i][j]==false) | i<=0 | j<=0 | sum<0)return;

  if( (i>0 && j>=0) && dp[i-1][j])trav(v,sum,i-1,j);
  if( (i>0 && sum>=v[i-1] ) && dp[i-1][sum-v[i-1]] ){
    ans.push_back(v[i-1]);
    trav(v,sum-v[i-1],i-1,sum-v[i-1]);
    ans.pop_back();
  }

return;
}

int main(){
  std::vector<int> v={1,3,16,5,4,7,11,13,15,20,6};
  int len=v.size();
  int tot=0;
  tr1(v)tot+=(*it);

  int query=8;
  int sum=tot-(tot%query);

  dp= std::vector<std::vector<bool> >(len+1,std::vector<bool>(sum+1,false));

  rep(len+1)dp[i][0]=true;

  for(int i=1;i<=len;i++){
    for(int j=1;j<=sum;j++){
      if(dp[i-1][j]==true)dp[i][j]=true;
      else if(j>=v[i-1] && dp[i-1][j-v[i-1]] )dp[i][j]=true;
      else dp[i][j]=false;
    }
  }
  // int p=0;
  // tr1(dp){
  //   cout<<(p++)<<" : ";
  //   rep((*it).size())cout<<(*it)[i]<<" ";
  //   cout<<endl;
  // }

  int p=1;
  while(query*p<=sum){
    trav(v,(query*p),len,(query*p));
    p++;
    cout<<" ------------------ "<<endl;
  }
  cout<<calls<<" CALLS"<<endl;
}
