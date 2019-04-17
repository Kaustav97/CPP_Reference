#include <iostream>
#include <math.h>
using namespace std;

class Node{
  int data;
  Node *next,*prev;
 public:
  Node *first;
   Node(){
     first=NULL;
   }
   void create(int);
   void reverse();
   void display();
   void del(int);
   Node list_union(Node,Node);
   Node list_intersection(Node,Node);
   Node list_symmdiff(Node,Node);
};

void Node::create(int num){
  Node *tmp=new Node;
  tmp->data=num;
  tmp->prev=tmp->next=NULL;
  if(first==NULL)first=tmp;
  else{
    Node *ctr;
    for(ctr=first;ctr->next;ctr=ctr->next);
    ctr->next=tmp;
    tmp->prev=ctr;
  }
}
void Node::display(){
  if(first==NULL){
    cout<<"EMPTY";
    return;
  }
  for(Node *ctr=first;ctr;ctr=ctr->next)cout<<ctr->data<<" ";
}
void Node::reverse(){
  Node *ctr;
  for(ctr=first;ctr->next;ctr=ctr->prev){
    Node *tmp=ctr->next;
    ctr->next=ctr->prev;
    ctr->prev=tmp;
  }
  ctr->next=ctr->prev;
  ctr->prev=NULL;
  first=ctr;
}
void Node::del(int val){
  Node *ctr;
    for(ctr=first;ctr->next;ctr=ctr->next){
      if(ctr->data==val){
        ctr->next->prev=ctr->prev;
        if(ctr->prev)ctr->prev->next=ctr->next;
        if(ctr==first)first=ctr->next;
      }
    }
    if(ctr->data==val)ctr->prev->next=NULL;
}
Node Node::list_union(Node f1,Node f2){
  Node ans;
  for(Node *ctr=f1.first;ctr;ctr=ctr->next){
    ans.create(ctr->data);
    f1.del(ctr->data);
    ctr=f1.first;
  }
  for(Node *ctr=f2.first;ctr;ctr=ctr->next){
    int flag=0;
    for(Node *c2=ans.first;c2;c2=c2->next){
      if(c2->data==ctr->data)flag=1;
    }
    if(flag)continue;
    else ans.create(ctr->data);
  }
  return ans;
}
Node Node::list_intersection(Node f1,Node f2){
  Node ans;
  for(Node *c1=f1.first;c1;c1=c1->next){
    for(Node *c2=f2.first;c2;c2=c2->next){
      if(c2->data==c1->data){
        ans.create(c1->data);
        f2.del(c2->data);
        c2=f2.first;
      }
    }
  }
  return ans;
}

Node Node::list_symmdiff(Node l1,Node l2){
  Node ans;
  for(Node *ctr=l1.first;ctr;ctr=ctr->next){
    int flag=0;
    for(Node *c2=l2.first;c2;c2=c2->next){
      if(ctr->data==c2->data){
        l1.del(ctr->data);
        l2.del(c2->data);
        flag=1;
      }
    }
    if(!flag)ans.create(ctr->data);
  }
  for(Node *ctr=l2.first;ctr;ctr=ctr->next)ans.create(ctr->data);
  return ans;
}

int main(){
  Node n1,n2,d;
  n1.create(10);n1.create(50);n1.create(20);
  n2.create(40);n2.create(10);n2.create(30);
  // Node un=d.list_union(n2,n1);
  // un.display();cout<<"\n";
  Node in=d.list_symmdiff(n1,n2);
  in.display();
}
