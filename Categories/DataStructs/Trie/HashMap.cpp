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
  bool isend;
  unordered_map<char,node*> chld;
  node():isend(false), chld(unordered_map<char,node*>()) {};
};

node* insert(node** head,string str){
  node* tmp=(*head);
  tr1(str){
    if(tmp->chld.find(*it)==tmp->chld.end() ){
      tmp->chld[*it]=new node();
    }
    tmp=tmp->chld[*it];
  }
  tmp->isend=true;
}

bool search(node** head,string str){
  if((*head)->chld.size()==0)return 0;
  node* tmp=(*head);
  tr1(str){
    tmp=tmp->chld[*it];
    if(!tmp)return false;
  }
  return tmp->isend;
}

int main(){
  // string str="hello hi my name nmem is kaustav name is hello is kaustav";
  string str="name nmem nemn";
  node* head=new node();
  insert(&head,"geeks");
  insert(&head,"for");

  cout<<search(&head,"geeks");

}
