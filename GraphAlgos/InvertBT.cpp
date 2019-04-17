#include <bits/stdc++.h>

using namespace std;

#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

struct node{
  int val;
  node *lft,*rgt;
  node(): lft(NULL),rgt(NULL) {};
  node(int n): val(n),lft(NULL),rgt(NULL) {};
};

void inorder(node **head){
  if((*head)->lft)inorder(&((*head)->lft));
  cout<<(*head)->val<<" ";
  if((*head)->rgt)inorder(&((*head)->rgt));
}

void invert(node **head,int lvl=2){
  // cout<<"at "<<(*head)->val<<endl;
  if (lvl%2==0){
    if((*head)->lft && (*head)->rgt ){
      node *tmp=(*head)->rgt;
      (*head)->rgt=(*head)->lft;
      (*head)->lft=tmp;
    }
    else if((*head)->lft && !((*head)->rgt) ){
      (*head)->rgt=(*head)->lft;
      (*head)->lft=NULL;
    }
    else if((*head)->rgt && !((*head)->lft) ){
      (*head)->lft=(*head)->rgt;
      (*head)->rgt=NULL;
    }
  }

  if((*head)->lft)invert(&((*head)->lft),lvl+1 );
  if((*head)->rgt)invert(&((*head)->rgt),lvl+1 );
}


int main(){
  node *head=new node(0);
  head->lft=new node(1);
  head->rgt=new node(2);

  head->lft->lft=new node(3);
  head->lft->rgt=new node(5);

  head->rgt->rgt=new node(9);

  inorder(&head); cout<<endl;
  invert(&head);
  inorder(&head); cout<<endl;
}
