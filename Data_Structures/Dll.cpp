#include <iostream>
using namespace std;

class Dll{
  int data;
  Dll *next,*prev;
 public:
   void create(int);
   void disp();
   void ins_before(int);
   void ins_aft(int);
   void rev();
   void del(int);
};
Dll *first=NULL;

void Dll::create(int num){
  Dll *tmp=new Dll;
  tmp->next=tmp->prev=NULL;
  tmp->data=num;
  if(first==NULL){
    first=tmp;
  }
  else{
    Dll *ctr=new Dll;
    for(ctr=first;ctr->next;ctr=ctr->next);
    ctr->next=tmp;
    tmp->prev=ctr;
  }
}
void Dll::disp(){
  for(Dll *ctr=first;ctr;ctr=ctr->next)cout<<ctr->data<<" ";
  cout<<"\n";
}
void Dll::ins_before(int val){
  Dll *tmp=new Dll;
  cout<<"Value to insert before "<<val<<": ";cin>>tmp->data;
  tmp->next=tmp->prev=NULL;
  if(first->data==val){
    tmp->next=first;first->prev=tmp;
    first=tmp;
  }
  else{
    Dll *ctr=new Dll;
    for(ctr=first;ctr;ctr=ctr->next){
      if(ctr->data==val){
        ctr->prev->next=tmp;tmp->prev=ctr->prev;
        ctr->prev=tmp;tmp->next=ctr;
      }
      if(!ctr)cout<<"Value diesn't exist\n";
    }
  }
}
void Dll::ins_aft(int val){
  Dll *tmp=new Dll;
  cout<<"Value to insert after "<<val<<": ";cin>>tmp->data;
  tmp->next=tmp->prev=NULL;
  for(Dll *ctr=first;ctr;ctr=ctr->next){
    if(ctr->data==val){
      tmp->next=ctr->next;
      if(ctr->next)ctr->next->prev=tmp;
      ctr->next=tmp;tmp->prev=ctr;
    }
    if(!ctr)cout<<"Value doesn't exist\n";
  }
}
void Dll::rev(){
  Dll *ctr=new Dll;
  for(ctr=first;ctr->next;ctr=ctr->prev){
    Dll* tmp=ctr->next;
    ctr->next=ctr->prev;
    ctr->prev=tmp;
  }
  ctr->next=ctr->prev;
  ctr->prev=NULL;
  first=ctr;
}
void Dll::del(int val){
  if(first->data==val)first=first->next;
  else{
    for(Dll *ctr=first->next;ctr;ctr=ctr->next){
      if(ctr->data==val){
        ctr->prev->next=ctr->next;
        if(ctr->next)ctr->next->prev=ctr->prev;
      }
    }
  }
}

int main(){
  Dll d1;
  int op=0;
  while(op!=7){
    cout<<"Enter operation:1.Create 2.Insert before  3.Insert after  4.display  5.delete  6.reverse  7.Exit\n";
    cin>>op;
    switch(op){
      case 1:
        int val;cout<<"First value: ";cin>>val;
        d1.create(val);break;
      case 2:
        int bef;
        cout<<"insert before: ";cin>>bef;
        d1.ins_before(bef);break;
      case 3:
        int aft;cout<<"insert after: ";cin>>aft;
        d1.ins_aft(aft);break;
      case 4:d1.disp();break;
      case 5:
        int del;
        cout<<"delete: ";cin>>del;
        d1.del(del);break;
      case 6:
        d1.rev();break;
    }
  }
}
