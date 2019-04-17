#include <bits/stdc++.h>

using namespace std;
#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second

int mulmod(int a, int b){
    ll res = 0;
    a = a % MOD;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res + a) % MOD;
        a = (a * 2) % MOD;
        b /= 2;
    }
    return res % MOD;
}

int main(){
  int tst; cin>>tst;
  while(tst--){
    int m,n; cin>>n>>m;
    vector<int> dp;
    if(m<n){cout<<0<<endl;continue;}

    dp.push_back(1);dp.push_back(1);
    for(int i=2;i<=n;i++){
      dp.push_back( mulmod(dp[i-1],2) );
    }

    for(int i=n+1;i<=m-n;i++){
      dp.push_back( ( mulmod(dp[i-1],2) - (dp[i-(n+1)])%MOD )%MOD  );
    }
    // tr(dp)cout<<*it<<" ";
    // cout<<endl;
    cout<<dp[m-n]<<endl;
  }
}
