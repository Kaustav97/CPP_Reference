#include <iostream>
#include "Structs\Sparse.cpp"
using namespace std;

void SlowTrans(Sparse sp[]){
  Sparse ans[100];int j=1;
  ans[0]=Sparse(sp[0].col,sp[0].row,sp[0].val);

  for(int j=0;j<=sp[0].row;j++){
    for(int i=1;i<=sp[0].val;i++){
      if(sp[i].col==j){
        ans[i].row=sp[i].col;
        ans[i].col=sp[i].row;
        ans[i].val=sp[i].val;
      }
    }
  }
  sp[0].Disp(ans);
}

int main(){
  Sparse A[100],d;
  int r,c,val;
  cout<<"Enter No. of rows: ";cin>>r;
  cout<<"Enter No. of cols: ";cin>>c;
  cout<<"Enter No. of Non-Zero elements: ";cin>>val;
  A[0]=Sparse(r,c,val);
  for(int i=1;i<=val;i++){
    cout<<"Enter row,col and val of element "<<i<<": ";
    cin>>A[i].row>>A[i].col>>A[i].val;
  }
  SlowTrans(A);


}
