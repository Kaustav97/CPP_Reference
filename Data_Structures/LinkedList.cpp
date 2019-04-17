#include <iostream>
using namespace std;

class Node{
  int data;
  Node *next;
public:
  void create(int);
  void disp();
  void ins_bef(int);
  void ins_aft(int);
  void reverse();
  void sort();
  void del_alt();
};
Node *first=NULL;

void Node::create(int num){
  Node *tmp,*ctr;
  ctr=tmp=new Node;
  tmp->data=num;
  tmp->next=NULL;
  if(first==NULL)first=tmp;
  else{
    for(ctr=first;ctr->next;ctr=ctr->next);
    ctr->next=tmp;
  }
}
void Node::disp(){
  if(first==NULL){
    cout<<"Empty";
    return;
  }
  for(Node *ctr=first;ctr;ctr=ctr->next)cout<<ctr->data<<" ";
}
void Node::ins_bef(int val){
  Node *tmp=new Node;
  cout<<"Value to insert before "<<val<<": ";cin>>tmp->data;
  tmp->next=NULL;
  if(first->data==val){
    tmp->next=first;
    first=tmp;
  }
  else{
    Node *ctr=new Node;
    for(ctr=first;ctr->next;ctr=ctr->next){
      if(ctr->next->data==val){
        tmp->next=ctr->next;
        ctr->next=tmp;
        break;
      }
    }
    if(!ctr->next)cout<<"Value doesn't exist\n";
  }
}
void Node::ins_aft(int val){
  Node *tmp=new Node;
  cout<<"Value to insert after "<<val<<": ";cin>>tmp->data;
  tmp->next=NULL;
  Node *ctr=new Node;
  for(ctr=first;ctr;ctr=ctr->next){
    if(ctr->data==val){
      tmp->next=ctr->next;
      ctr->next=tmp;
    }
    if(!ctr)cout<<"Value doesn't exist\n";
  }
}
void Node::reverse(){
  Node *curr,*prev,*tmp;
  curr=prev=new Node;
  prev=first;
  for(curr=first->next;curr;){
    tmp=curr->next;
    curr->next=prev;
    if(prev==first)prev->next=NULL;
    prev=curr;
    curr=tmp;
  }
  first=prev;
}
void Node::del_alt(){
  Node *curr,*prev;
  prev=first;
  for(curr=first->next;prev!=0 & curr!=0;){
    prev->next=curr->next;
    prev=curr->next;
    if(prev)curr=prev->next;
  }
}

int main(){
  Node l1;
  l1.create(10);l1.create(20);l1.create(30);
  //l1.ins_aft(10);
  l1.del_alt();
  l1.disp();
}
