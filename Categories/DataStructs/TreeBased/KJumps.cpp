#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

struct node{
  int data;
  node *left,*right;
  node(int n): data(n),left(NULL),right(NULL) {};
};
void inorder(node **head){
  if((*head)->left)inorder(&((*head)->left));
  cout<<(*head)->data<<" ";
  if((*head)->right)inorder(&((*head)->right));
}
node* init(){
  node *head=new node(10);
  head->left=new node(20);
  head->right=new node(30);

  head->left->left=new node(40);
  head->left->right=new node(50);
  head->right->right=new node(60);
  head->right->left=new node(70);

  head->left->left->left=new node(90);
  head->left->right->left=new node(70);
  head->left->right->right=new node(15);
  head->right->right->right=new node(12);

  head->left->right->left->left=new node(8);
  head->left->right->left->right=new node(9);

  return head;
}


/*
STRUCTURE:
               10
              / \
            20  30
           / \   \
         40  50  60
        /   / \   \
      90   70 15  12
          / \
         8  9
# of nodes = 12
# of edges = 9

*/

int main(){
  // Create above tree:
  node *head=init();
  inorder(&head);

}
