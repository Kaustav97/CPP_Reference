#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <math.h>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

struct node{
  int data;
  node *left,*right;
  node *nxt;
  node(int n): data(n),left(NULL),right(NULL),nxt(NULL) {};
};

node* init(){
  node *head=new node(10);
  head->left=new node(20);
  head->right=new node(30);

  head->left->left=new node(40);
  head->left->right=new node(50);
  head->right->right=new node(60);

  head->left->left->left=new node(90);
  head->left->right->left=new node(70);
  head->left->right->right=new node(15);
  head->right->right->right=new node(12);

  head->left->right->left->left=new node(8);
  head->left->right->left->right=new node(9);
  return head;
}

node *rgt=NULL;
void connectlevel(node **head,int lvl){
  if(lvl==1){
    (*head)->nxt=rgt;
    rgt=(*head);
    return;
  }
  if((*head)->right) connectlevel(&((*head)->right),lvl-1 );
  if((*head)->left) connectlevel(&((*head)->left),lvl-1 );
}


/*
STRUCTURE:
               10
              / \
            20  30
           / \   \
         40  50  60
        /   / \   \
      90  70  15  12
         / \
        8  9

*/

int main(){
  node *head=init();

  connectlevel(&head,1);rgt=NULL;
  connectlevel(&head,4);rgt=NULL;
  connectlevel(&head,2);rgt=NULL;
  connectlevel(&head,3);rgt=NULL;
  connectlevel(&head,5);rgt=NULL;

  while(head){
    node *ctr=head;
    while(ctr){
      cout<<ctr->data<<"-";
      ctr=ctr->nxt;
    }
    head=head->left;
    cout<<endl;
  }

}
