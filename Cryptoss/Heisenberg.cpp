#include <bits/stdc++.h>

using namespace std;
#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second

int gcd (int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

ll mulmod(ll a, ll b){
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
  int a,b; cin>>a>>b;
  ll ans=0;
  for(int i=a;i<b;i++){
    for(int j=i+1;j<=b;j++){
      if(gcd(i,j)==1){
        // cout<<"("<<i<<","<<j<<") ";
        ans = (ans + mulmod(i,j) )%MOD;
      }
    }

  }
  cout<<ans<<endl;
}
