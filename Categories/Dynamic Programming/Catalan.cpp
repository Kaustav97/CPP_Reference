#include <iostream>
#include <vector>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

//  CALCULATE nCr
//  // O(n*r) space and O(n^2) time:
long long Onr(int N,int R){
  std::vector<std::vector<long long> > ncr(N+1,std::vector<long long>(R+1,1));

  for(int i=2;i<=N;i++){
    for(int j=1;j<=R;j++){
      if(i==j)ncr[i][j]=1;
      else ncr[i][j]=ncr[i-1][j-1] + ncr[i-1][j];
    }
  }

  return ncr[N][R];
}

// // O(r) space and O(n^2) time:
long long Or_space(int N,int R){
  std::vector<std::vector<long long> > ncr(2,std::vector<long long>(R+1,1));
  int pos=2;
  while(pos<=N){

    for(int i=1;i<=R;i++){
      if(i==pos)ncr[1][i]=1;
      else ncr[1][i]=ncr[0][i-1] + ncr[0][i];
    }
    ncr.erase(ncr.begin());
    ncr.resize(2);
    ncr[1]=std::vector<long long>(R+1,1);
    pos++;
  }
  ncr.erase(ncr.end()-1);
  // ncr[3][2] = ncr[2][1] + ncr[2][2];

  // tr1(ncr[0]){
  //   cout<<*it<<" ";
  //   // rep((*it).size())cout<<(*it)[i]<<" ";
  //   // cout<<endl;
  // }

  return ncr[0][R];

}

// O(1) space and O(r) time:
double opt_ncr(int N,int R){
  double ans=1;
  int tmp=R;

  while(R>=1){
    ans*=(N--);
    ans/=(R--);
  }

  // while(R>=1){ans*=(N--); R--;}
  // while(tmp>=1)ans/=(tmp--);

  return ans;
}

long long Catalan(int R){
  int N=2*R;
  return opt_ncr(N,R)/(R+1);
}

int main(){
  // Catalan Numbers :- Cat(n)= (1/n+1) * 2nCn
  // C(n,r)= C(n-1,r-1) + C(n-1,r)
  for(int i=0;i<=40;i++)cout<<Catalan(i)<<" ";
}
