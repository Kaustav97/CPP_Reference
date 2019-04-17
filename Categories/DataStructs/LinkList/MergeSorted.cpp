#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

struct node{
  int data;
  node *nxt;
  node(int n): data(n),nxt(NULL) {}
};

void push(node **head,int val){
  node *n1=new node(val);
  n1->data=val;
  n1->nxt=NULL;

  if(!(*head)) (*head)=n1;
  else{
    node *ctr=(*head);
    while(ctr->nxt)ctr=ctr->nxt;
    ctr->nxt=n1;
  }
}

void display(node **cur){
  if(!(*cur))return;
  cout<<(*cur)->data<<" ";
  display(&(*cur)->nxt) ;
}

void create(node **l1,std::initializer_list<int> args){
  tr1(args){
    push(&(*l1),*it);
  }
}

int main(){
  node *head=NULL;
  create(&head,{1,2,3,4,5,6});
  display(&head);
}
