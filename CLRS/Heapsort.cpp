#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

class heap{
  std::vector<int> v;
public:
   heap(std::vector<int> v2){
     v=v2;
   }
   int parent(int i){return (i>>1);}
   int left(int i){return (i<<1);}
   int right(int i){return (i<<1)+1;}
   void display();
   void heapify(int);
   void buildheap();
   void sort();
   std::vector<int> output();
};

void heap::display(){
  tr1(v)cout<<*it<<" ";
  cout<<endl;
}
void heap::heapify(int i){
  int l=left(i);
  int r=right(i);

  // cout<<l<<" "<<r<<endl;
  // cout<<" par- "<<p<<endl;

  int lrg;
  if(l<v.size() & v[l]>v[i]) lrg=l;
  else lrg=i;
  if(r<v.size() & v[r]>v[lrg]) lrg=r;

  if(lrg!=i){
    int tmp=v[i];
    v[i]=v[lrg];
    v[lrg]=tmp;
    heapify(lrg);
  }
}
void heap::buildheap(){
  for(int i=v.size()/2;i>=1;i--){
    // display();
    heapify(i);
  }
}
void heap::sort(){
  // display();
  if(v.size()==1){cout<<endl;return;}
  cout<<v[1]<<" ";
  v[1]=v[v.size()-1];
  v.erase(v.end()-1);
  heapify(1);
  sort();
}
std::vector<int> heap::output(){
  return v;
}

class priority{
  std::vector<int> v;
 public:
   void add(int i){v.push_back(i);}
   int high();
   void display();
};

int priority::high(){
  heap h1(v);
  h1.buildheap();
  v=h1.output();
  int ans=v[1];
  v.erase(v.begin()+1);
  return ans;
}
void priority::display(){
  tr1(v)cout<<*it<<" ";
  cout<<endl;
}

int main(){
  std::vector<int> v={NULL,5,6,1,2,3,9,2,4,10};

  heap l1(v);
  l1.buildheap();
  l1.sort();

  priority p1;
  tr1(v)p1.add(*it);
  cout<<p1.high()<<endl;
  p1.display();
}
