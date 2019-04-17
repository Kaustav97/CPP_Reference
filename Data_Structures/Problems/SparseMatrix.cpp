#include <iostream>
using namespace std;

class Sparse{
  int row,col,val;
 public:
   Sparse();
   Sparse(int,int,int);
   void slowTrans(Sparse*);
   void fastTrans(Sparse*);
   void display(Sparse*);
};
Sparse::Sparse(){
  row=col=val=0;
}
Sparse::Sparse(int r,int c,int v){
  row=r;col=c;val=v;
}
void Sparse::slowTrans(Sparse sp[]){
  Sparse ans[sp[0].val+1],d;
  int pos=1;
  for(int i=0;i<=sp[0].col;i++){
    for(int j=1;j<=sp[0].val;j++){
      if(sp[j].col==i){
        ans[pos].row=sp[j].col;
        ans[pos].col=sp[j].row;
        ans[pos].val=sp[j].val;
        pos++;
      }
    }
  }
  ans[0].row=sp[0].col;
  ans[0].col=sp[0].row;
  ans[0].val=sp[0].val;
  d.display(ans);
}

void Sparse::fastTrans(Sparse sp[]){
  Sparse ans[sp[0].val+1],d;
  int rowterm[sp[0].col],startpos[sp[0].col];
  for(int i=0;i<sp[0].col;i++)rowterm[i]=0;
  for(int i=1;i<=sp[0].val;i++){
    rowterm[sp[i].col]++;
  }
  startpos[0]=1;
  for(int i=1;i<sp[0].col;i++)startpos[i]=startpos[i-1]+rowterm[i-1];
  for(int i=1;i<=sp[0].val;i++){
    int pos=startpos[sp[i].col];
    ans[pos]=Sparse(sp[i].col,sp[i].row,sp[i].val);
    startpos[sp[i].col]++;
  }
  ans[0]=Sparse(sp[0].col,sp[0].row,sp[0].val);
  d.display(ans);
}

void Sparse::display(Sparse sp[]){
  cout<<"Row\tCol\tVal\n";
  for(int i=0;i<=sp[0].val;i++){
    cout<<sp[i].row<<"\t"<<sp[i].col<<"\t"<<sp[i].val<<"\n";
  }
}
int main(){
  int r,c,v;
  cin>>r>>c>>v;
  Sparse mat[v+1],d;
  cout<<"Enter Matrix:\n";
  mat[0]=Sparse(r,c,v);
  for(int i=1;i<=v;i++){
    int r1,c1,v1;
    cin>>r1>>c1>>v1;
    mat[i]=Sparse(r1,c1,v1);
  }
  d.fastTrans(mat);
}
