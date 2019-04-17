#include <bits/stdc++.h>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second

struct node{
  string op;
  node* lft;
  node* rgt;
  node(): lft(NULL),rgt(NULL) {};
  node(string str): op(str),lft(NULL),rgt(NULL) {};
};

node* init(){
  node *head=new node("-");
  head->lft=new node("/");
  head->rgt=new node("+");

  head->lft->lft=new node("+");
  head->lft->rgt=new node("3");
  head->rgt->lft=new node("7");
  head->rgt->rgt=new node("12");

  head->lft->lft->lft=new node("5");
  head->lft->lft->rgt=new node("7");

  return head;
}

void inorder(node **head){
  if((*head)->lft)inorder(&((*head)->lft));
  cout<<(*head)->op<<" ";
  if((*head)->rgt)inorder(&((*head)->rgt));
}

std::vector<int> stk;
void evaluate(node** head){
  if((*head)->lft)evaluate(&((*head)->lft));
  if((*head)->rgt)evaluate(&((*head)->rgt));
  try{
    int num=stoi((*head)->op);
    stk.push_back(num);
  }
  catch(...){
    int op1=stk.back(); stk.pop_back();
    int op2=stk.back(); stk.pop_back();
    if((*head)->op=="+") stk.push_back(op2+op1);
    if((*head)->op=="-") stk.push_back(op2-op1);
    if((*head)->op=="*") stk.push_back(op2*op1);
    if((*head)->op=="/") stk.push_back(op2/op1);
  }

}

int main(){
  node *head=init();
  inorder(&head); cout<<endl;
  evaluate(&head);
  cout<<stk[0];
}
