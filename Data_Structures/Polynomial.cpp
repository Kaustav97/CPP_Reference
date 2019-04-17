#include <iostream>
using namespace std;

class poly{
  int coeff,exp;
  poly* next;
 public:
   poly *first;
   poly(){first=NULL;}
   void create(int,int);
   void disp();
   poly add(poly p1,poly p2);
   poly mult(poly p1,poly p2);
};

void poly::create(int cf,int xp){
  poly *tmp=new poly();
  tmp->coeff=cf;tmp->exp=xp;
  tmp->next=NULL;
  if(first==NULL){
    first=tmp;
  }
  else{
    poly *ctr;
    for(ctr=first;ctr->next;ctr=ctr->next);
    ctr->next=tmp;
  }
}
void poly::disp(){
  if(first==NULL){
    cout<<"Empty";
    return;
  }
  for(poly *ctr=first;ctr;ctr=ctr->next)cout<<ctr->coeff<<"x^"<<ctr->exp<<"+";
  cout<<"\n";
}
poly poly::add(poly p1,poly p2){
  poly ans;
  for(poly *ctr=p1.first;ctr;ctr=ctr->next)ans.create(ctr->coeff,ctr->exp);
  for(poly *c1=ans.first;c1;c1=c1->next){
    for(poly *c2=p2.first;c2;c2=c2->next){
      if(c2->exp==c1->exp){
        c1->coeff+=c2->coeff;
        c2->exp=-1;
      }
    }
  }
  for(poly *ctr=p2.first;ctr;ctr=ctr->next){
    if(ctr->exp!=-1)ans.create(ctr->coeff,ctr->exp);
  }
  return ans;
}

poly poly::mult(poly p1,poly p2){
  poly ans;
  for(poly *c1=p1.first;c1;c1=c1->next){
    poly tmp;
    for(poly *c2=p2.first;c2;c2=c2->next){
      tmp.create(c1->coeff*c2->coeff,c1->exp+c2->exp);
    }
    ans=ans.add(ans,tmp);
  }
  return ans;
}

int main(){
  poly p1,p2,p3,d;
  p1.create(1,5);p1.create(1,4);p1.create(1,2);p1.create(1,0);
  p2.create(1,4);p2.create(1,3);p2.create(1,1);
  p3.create(1,4);p3.create(1,3);p3.create(1,2);p3.create(1,1);p3.create(1,0);
//  d=d.mult(p1,p2);
  d=d.add(d,p3);
  d.disp();
}
