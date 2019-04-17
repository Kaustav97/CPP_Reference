#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

class node{
public:
  int val;
  node *nxt;
   node *fst;
   node(){
     fst=NULL;
   }
   void create(int);
   void display();
   // void partrev(int);
   // void reverse();
};
void node::create(int num){
  node *tmp=new node;
  tmp->val=num;
  tmp->nxt=NULL;
  if(fst==NULL)fst=tmp;
  else{
    node *ctr;
    for(ctr=fst;ctr->nxt;ctr=ctr->nxt);
    ctr->nxt=tmp;
  }
}
void node::display(){
  if(fst==NULL)cout<<"Empty";
  else{
    for(node *ctr=fst;ctr;ctr=ctr->nxt)cout<<ctr->val<<" ";
    cout<<endl;
  }
}

node reverse(node &lst){
  if(lst.fst==NULL)return lst;
  node *prev=lst.fst,*curr=lst.fst->nxt;
  while(curr){
    node *tmp=curr->nxt;
    curr->nxt=prev;
    prev=curr;
    curr=tmp;
  }
  lst.fst->nxt=NULL;
  lst.fst=prev;
  return lst;
}

int main(){
  node l1,l2;
  l1.create(1);l1.create(2);l1.create(3);
  l1.create(4);l1.create(5);l1.create(6);

  l1.display();
  reverse(l1);l1.display();

}
