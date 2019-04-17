#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

class longInt{
  int val,exp;
  longInt* next;
 public:
   longInt *first;
   longInt(){first=NULL; }
   void create(int,int);
   void disp();
   longInt add(longInt p1,longInt p2);
   longInt mult(longInt p1,longInt p2);
};
void longInt::create(int cf,int xp){
  longInt *tmp=new longInt();
  tmp->val=cf;tmp->exp=xp;
  tmp->next=NULL;
  if(first==NULL){
    first=tmp;
  }
  else{
    longInt *ctr;
    for(ctr=first;ctr->next;ctr=ctr->next);
    ctr->next=tmp;
  }
}
void longInt::disp(){
  if(first==NULL){
    cout<<"Empty";
    return;
  }
  long ans=0;
  longInt *ctr;
  for(ctr=first;ctr;ctr=ctr->next)ans+=ctr->val*(pow(10,ctr->exp));
  cout<<ans<<"\n";
}
longInt longInt::add(longInt l1,longInt l2){
  longInt ans;
  int high=0;
  for(longInt *c1=l1.first;c1;c1=c1->next)if(c1->exp>high)high=c1->exp;
  for(longInt *c1=l2.first;c1;c1=c1->next)if(c1->exp>high)high=c1->exp;
  int carry=0;
  for(int i=0;i<=high;i++){
    int d1=0,d2=0;
    for(longInt *c1=l1.first;c1;c1=c1->next)if(c1->exp==i)d1=c1->val;
    for(longInt *c1=l2.first;c1;c1=c1->next)if(c1->exp==i)d2=c1->val;
    int sum=(d1+d2+carry)%10;
    carry=(d1+d2+carry)/10;
    if(i<high)ans.create(sum,i);
    else ans.create(d1+d2+carry,i);
  }
  return ans;
}

int main(){
  longInt l1,l2,d;
  l1.create(3,4);l1.create(9,3);l1.create(9,1);l1.create(9,0);
  l2.create(9,3);l2.create(9,2);l2.create(9,1);l2.create(9,0);
  l1.disp();cout<<" ";l2.disp();
  cout<<"----\n";
  d=d.add(l1,l2);
  d.disp();
  getchar();
}
