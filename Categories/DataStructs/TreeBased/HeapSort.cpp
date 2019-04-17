#include <bits/stdc++.h>
using namespace std;

#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++ )
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

void inorder(node **head){
  if( (*head)->left )inorder(&((*head)->left));
  cout<<(*head)->data<<" ";
  if( (*head)->right )inorder(&((*head)->right));
}

int calls=0;
void sink(node **curr){
  if( (*curr)->left!=NULL && ((*curr)->data < (*curr)->left->data ) ) {
    calls++;
    int tmp=(*curr)->data;
    (*curr)->data= (*curr)->left->data;
    (*curr)->left->data=tmp;
    // cout<<(*curr)->data<<endl;
    sink(&((*curr)->left) );
  }
  else if( (*curr)->right!=NULL && ((*curr)->data < (*curr)->right->data) ){
    calls++;
    int tmp=(*curr)->data;
    (*curr)->data= (*curr)->right->data;
    (*curr)->right->data=tmp;
    // cout<<(*curr)->data<<endl;
    sink( &((*curr)->right) );
  }
}

void heapify(node **head){
  if((*head)->left && (*head)->left->data>0 ) heapify(&((*head)->left) );
  sink(&(*head));
  if((*head)->right && (*head)->right->data>0 )heapify(&((*head)->right) );
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

  heapify(&head);
  while(head->data>0){
    // if(head->data==50)break;
    cout<<head->data<<" ";
    head->data=-1;
    sink(&head);
    heapify(&head);
  }

  cout<<endl<<calls<<" calls"<<endl;
}
