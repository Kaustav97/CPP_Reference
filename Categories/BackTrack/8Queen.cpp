#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int n;
std::vector<bool> row,col,d1,d2;

int calls=0;
bool stop=0;

bool isopen(int r,int c){
  return ( (row[r] & col[c]) & d1[r+c] & d2[(n-1)+c-r] );
}

void state(){
  // cout<<"row - "; tr1(row)cout<<*it<<" "; cout<<endl;
  // cout<<"col - "; tr1(col)cout<<*it<<" "; cout<<endl;
  // cout<<"diag / - "; tr1(d1)cout<<*it<<" "; cout<<endl;
  // cout<<"diag \\ - "; tr1(d2)cout<<*it<<" "; cout<<endl;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<( (row[i] & col[j]) & d1[i+j]  &  d2[4+j-i] )<<" ";
    }
    cout<<endl;
  }
}

void place(int i,int j){
  row[i]=0; col[j]=0;
  d1[i+j]=0; d2[(n-1)+j-i]=0;
}

void rem(int i,int j){
  row[i]=1; col[j]=1;
  d1[i+j]=1; d2[(n-1)+j-i]=1;
}

void findways(int r,std::vector<pair<int,int> > ans){
  if(r==row.size()){
    tr1(ans)cout<<"("<<it->first<<","<<it->second<<") ";
    cout<<endl; stop=1;
    return;
  }
  bool flag=0;

  for(int i=0;i<n;i++){
    if(isopen(r,i)){
      place(r,i);

      cout<<r<<" :"<<endl;
      state();
      cout<<" -------------------- \n";
      calls++;

      flag=1;
      ans.push_back(make_pair(r,i));
      // if(!stop)findways(r+1,ans);
      findways(r+1,ans);
      rem(r,i); ans.pop_back();
    }
  }
  if(!flag)return;

}

int main(){
  n=4;
  row=col=std::vector<bool>(n,1);
  d1=d2=std::vector<bool>(2*(n-1)+1,1);

  cout<<"WORKING . . . ."<<endl;

  std::vector<pair<int,int> > ans;
  findways(0,ans);
  // place(0,1); state();
  // cout<<calls<<" calls"<<endl;
  //brd(i,j):  row[i], col[j], d1[i+j], d2[j-i+4]
  cout<<"DONE ! "<<endl;
}
