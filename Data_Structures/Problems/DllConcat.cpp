#include <iostream>
using namespace std;

class List{
  int data;
  List *next,*prev;
 public:
   void create(List*,int);
   void disp(List*);
   void concat(List*,List*);
};
List *first1=NULL;
List *first2=NULL;

void List::create(List *f1,int num){
  List *tmp=new List;
  tmp->data=num;
  tmp->next=NULL;
  if(f1==NULL)f1=tmp;
  else{
    List *ctr;
    for(ctr=f1;ctr->next;ctr=ctr->next);
    ctr->next=tmp;
  }
}

void List::disp(List *l1){
  for(List *ctr=l1;ctr;ctr=ctr->next)cout<<ctr->data<<" ";
  cout<<"\n";
}

void List::concat(List *l1,List *l2){
  List *l3;
  if(!l1)l3=l2;
  else if(!l2)l3=l1;
  else{
    List*c;
    for(c=l1;c->next;c=c->next);
    c->next=l2;
    l2->prev=c;
    l3=l1;
  }
  l1=l3;
}

int main(){
  List d;
  d.create(first1,10);d.create(first1,20);
  d.disp(first1);
}
