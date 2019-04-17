#include <iostream>
#include "Structs/Sparse.cpp"
using namespace std;

void FastTrans(Sparse sp[]){
  int r=sp[0].row,c=sp[0].col,v=sp[0].val;
  Sparse ans[v+1],d;
  int rowterm[c],startpos[c];
  for(int i=0;i<c;i++)rowterm[i]=0;
  for(int i=1;i<=v;i++)rowterm[sp[i].col]++;
  startpos[0]=1;
  for(int i=1;i<c;i++)startpos[i]=rowterm[i-1]+startpos[i-1];
  ans[0]=Sparse(c,r,v);
  for(int i=1;i<=v;i++){
    int pos=startpos[sp[i].col];
    ans[pos]=Sparse(sp[i].col,sp[i].row,sp[i].val);
    startpos[sp[i].col]++;
  }
  d.Disp(ans);
}

int main(){
  Sparse sp[10],d;
  int r,c,v;
  cout<<"Enter No. of Rows, Columns, and Non-Zero Elements: ";
  cin>>r>>c>>v;
  sp[0]=Sparse(r,c,v);
  for(int i=1;i<=v;i++){
    int r1,c1,v1;
    cout<<"Row, Col, Val "<<i<<": ";cin>>r1>>c1>>v1;
//    cout<<"Col "<<i<<": ";cin>>c1;
//    cout<<"Value "<<i<<": ";cin>>v1;
    sp[i]=Sparse(r1,c1,v1);
  }
  //d.Disp(sp);
  FastTrans(sp);
}
