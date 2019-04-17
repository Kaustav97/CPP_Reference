#include <bits/stdc++.h>
using namespace std;

#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++ )
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

struct node{
  int freq;
  unordered_map<char,node*> chld;
  node(): freq(0){};
};

int mx=0;
map<string,int> ans;

void insert(node** head,string str){
  node* tmp=(*head);
  tr1(str){
    if(tmp->chld.find(*it)==tmp->chld.end()){
      node *nxt=new node();
      tmp->chld.insert(make_pair(*it,nxt) );
      tmp=tmp->chld[*it];
    }
    else tmp=tmp->chld[*it];
  }
  tmp->freq++;

  if(ans.find(str)==ans.end() )ans.insert(make_pair(str,tmp->freq));
  else ans[str]++;

  if((tmp->freq)>mx){
    mx=tmp->freq;
  }
}

int main(){
  node* head=new node();
  std::vector<string> wrds={"hello","stranger","my","name","is","name","hello","is","stranger","name", "hello", "hello" };
  tr1(wrds)insert(&head,*it);

  std::map<int,string,greater<int> > ord;
  tr1(ans){
    ord[it->second]=it->first;
  }
  ans.clear();

  // tr1(ord)cout<<(*it).first<<" "<<(*it).second<<endl;

}
