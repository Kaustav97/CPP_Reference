#include <iostream>
using namespace std;

class Sparse{
public:
  int row,col,val;
  Sparse(int r,int c,int v){
    row=r,col=c,val=v;
  }
  Sparse(){
    row=col=val=0;
  }
  void Disp(Sparse[]);
};
void Sparse::Disp(Sparse sp[]){
  cout<<"ROW\tCOL\tVALUE\n";
  for(int i=0;i<=sp[0].val;i++){
    cout<<sp[i].row<<"\t"<<sp[i].col<<"\t"<<sp[i].val<<"\n";
  }
}
