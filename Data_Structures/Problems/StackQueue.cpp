#include <iostream>
using namespace std;

class Node{
  int data;
  Node *next;
 public:
   void disp();
   int del_pop();
   int del_deq();
   void ins_push(int);
   void ins_enq(int);
};
Node *first=NULL;

void Node::disp(){
  if(first==NULL){
    cout<<"Empty";
    return;
  }
  for(Node *ctr=first;ctr;ctr=ctr->next)cout<<ctr->data<<" ";
  cout<<"\n";
}

int Node::del_pop(){
  Node *ctr=new Node;
  for(ctr=first;ctr->next->next;ctr=ctr->next);
  int r=ctr->next->data;
  ctr->next=NULL;
  return r;
}

void Node::ins_push(int num){
  Node *tmp=new Node;
  tmp->next=NULL;tmp->data=num;
  if(first==NULL)first=tmp;
  else{
    Node *ctr;
    for(ctr=first;ctr->next;ctr=ctr->next);
    ctr->next=tmp;
  }
}

void Node::ins_enq(int num){
  ins_push(num);
}

int Node::del_deq(){
  int r=first->data;
  first=first->next;
  return r;
}

int main(){
  Node ls,lq;
  int op=0;
  while(op!=7){
    cout<<"Enter operation: 1.Stack push 2.Stack pop 3.Stack display 4.Enque 5.Deque 6.Queue display 7.exit\n";
    cin>>op;
    switch(op){
      case 1:
        int stkval;
        cout<<"insert: ";cin>>stkval;
        ls.ins_push(stkval);break;
      case 2:
        ls.del_pop();break;
      case 3:
        ls.disp();break;
      case 4:
        int qval;
        cout<<"Insert: ";cin>>qval;
        lq.ins_enq(qval);break;
      case 5:
        lq.del_deq();break;
      case 6:
        lq.disp();
    }
  }
}
