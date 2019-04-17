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

  head->left->left->left=new node(90);
  head->left->right->left=new node(70);
  head->left->right->right=new node(15);
  head->right->right->right=new node(12);

  head->left->right->left->left=new node(8);
  head->left->right->left->right=new node(9);

  return head;
}

unordered_map<int,std::vector<int> > anc;

void precomp(node **head){
  // calls++;
  std::vector<int> v=anc[(*head)->data];

  v.insert( v.begin(),((*head)->data) ) ;

  if((*head)->left)  anc[((*head)->left)->data]=v;
  if((*head)->right) anc[((*head)->right)->data]=v;

  if((*head)->left) precomp( &((*head)->left) );
  if((*head)->right) precomp( &((*head)->right) );
}

int dist(int n1,int n2){
  int lw,hg;
  if(anc[n1].size()>anc[n2].size()){lw=n1; hg=n2; }
  else {lw=n2; hg=n1; }
  rep(anc[lw].size()){
    if(anc[lw][i]==hg)return (i+1);
  }

  for(int i=0;i<anc[lw].size();i++ ){
    for(int j=0;j<anc[hg].size();j++ ){
      if(anc[hg][j]==anc[lw][i])return (i+j+2);
    }
  }

}


map<int,std::vector<int> >lvl;
void findlevels(node **head,int curlev=1){
  if(lvl.find(curlev)==lvl.end() ){
    lvl[curlev]=std::vector<int>{(*head)->data};
  }
  else{
    lvl[curlev].push_back((*head)->data);
  }
  if((*head)->left) findlevels( &((*head)->left),curlev+1);
  if((*head)->right) findlevels( &((*head)->right),curlev+1);
}

void eulertour(node **head){
  cout<<(*head)->data<<" ";
  if((*head)->left){
    eulertour(&((*head)->left));
    cout<<(*head)->data<<" ";
  }

  if((*head)->right){
    eulertour(&((*head)->right));
    cout<<(*head)->data<<" ";
  }

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
# of nodes = 12
# of edges = 9

*/


int main(){
  node *head=init();

  //  DISTANCE BETWEEN ANY 2 NODES:
  // /*
  anc[head->data]=std::vector<int>{};
  precomp(&head);
  tr1(anc){
    cout<<it->first<<": ";
    rep((it->second).size())cout<<(it->second)[i]<<" ";
    cout<<endl;
  }
  cout<<dist(8,12);
  // */


  // EULER TOUR:
  // eulertour(&head);

  //FIND NODES IN EACH LEVEL:  -- HASHMAP
  // findlevels(&head);
  // tr1(lvl){
  //   cout<<it->first<<": ";
  //   rep((it->second).size())cout<<(it->second)[i]<<" ";
  //   cout<<endl;
  // }

  // Mirror given tree:

}
