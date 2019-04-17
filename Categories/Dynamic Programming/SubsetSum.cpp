#include <iostream>
#include <vector>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int main(){
  std::vector<int> v={3,3,17,5,9,1};
  int sum=25,n=v.size();

  // // DP- Space O(n*sum)

  // std::vector<std::vector<bool> > sub(n+1,std::vector<bool>(sum+1,false));
  // rep(n+1)sub[i][0]=true;
  // sub[i][j] -> subset of sum j exists in v[0 : i]

  // for(int i=1;i<=n;i++){
  //   for(int j=1;j<=sum;j++){
  //     if(j<v[i-1])sub[i][j]=sub[i-1][j];
  //     else sub[i][j]= ( (sub[i-1][j]) | (sub[i-1][j-v[i-1]] && j>=v[i-1]) );
  //   }
  // }

  // // DP- Space O(sum)

  std::vector<std::vector<bool> > sub(2,std::vector<bool>(sum+1,false));
  sub[0][0]=true; sub[1][0]=true;

  int pos=0;
  while(pos<v.size()){
    for(int i=1;i<=sum;i++){
      if(pos==v.size())break;
      if(i<v[pos])sub[1][i]=sub[0][i];
      else sub[1][i]=( sub[0][i] | (sub[0][i-v[pos]] && i>=v[pos] ) );
    }

    if(pos==v.size()-1){
      tr1(sub){
        rep((*it).size()){
          cout<<(*it)[i]<<"  ";
        }
        cout<<endl;
      }

    }


    sub.erase(sub.begin());
    sub.resize(2);
    sub[1]=std::vector<bool>(sum+1,false);
    sub[1][0]=true;
    pos++;
  }


  cout<<sub[0][sum];

  rep(sum+1){
    cout<<i<<" ";
    if(i<10) cout<<" ";
  }
  cout<<endl;
  rep(3*sum+1) cout<<'-'; cout<<endl;

  // tr1(sub){
  //   rep((*it).size()){
  //     cout<<(*it)[i]<<"  ";
  //   }
  //   cout<<endl;
  // }

}
