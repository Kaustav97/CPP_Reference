#include <iostream>
#include <vector>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

long hgh=0;
int call=0;
void mxsum_rec(std::vector<int> &v,int pos,long sum){
  if(pos>=v.size()){
    if(sum>hgh)hgh=sum;
    cout<<sum<<endl;
    return;
  }
  call++;
  // take i
  mxsum_rec(v,pos+2,sum+v[pos]);

  // take i+1
  if(pos+1<v.size())mxsum_rec(v,pos+3,sum+v[pos+1]);

  return;
}

void mxsum_dp(std::vector<int> &v){
  long inc,exc;
  inc=exc=0;
  tr1(v){
    long tmp=inc;
    inc=exc+(*it);
    exc=tmp;
    // cout<<inc<<" "<<exc<<endl;
  }
  cout<<max(inc,exc);
}

int main(){
  // int tst;cin>>tst;
  // for(int i=0;i<tst;i++){
    hgh=0;
    // int n; cin>>n;
    // std::vector<int> v(n);
    // rep(n)cin>>v[i];

    // std::vector<int> v={5,5,10,40,50,35};
    std::vector<int> v={5,15,7,8,9,20,3,4,5,55,55,55,70,18,15,13,14,0,1,2};
    mxsum_rec(v,0,0);
    cout<<hgh<<" - "<<call<<"calls"<<endl;

    mxsum_dp(v);


  // }

}
