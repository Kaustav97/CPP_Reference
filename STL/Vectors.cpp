#include <stack>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

// define such macros to quickly continue after this code!
// DO NOT PUT ; AT THE END, to execute loops
#define tr(cont,it) for(auto it=cont.begin();it!=cont.end();it++)
// Useful to define multiple interval macros
#define present(container,element) (container.find(element)!=container.end())
// FOR VECTOR:
#define vec_present(container,element) (find(container.begin(),container.end(),element) != container.end() )

// ############ VECTORS ##############
// O(1) access, resizeable, extended array functionality
void disp(const vector<int> &v){
  // omit const to change vector
  for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
}
void rev(vector<int> &v){
  for(int i=0;i<v.size()/2;i++){
    // cout<<'\n'<<v[v.size()-i-1];
    int tmp=v[i];
    v[i]=v[v.size()-i-1];
    v[v.size()-i-1]=tmp;
  }
}

// void permute(const vector<int> tst){
//   vector<int>::iterator it=tst.begin();
//
//   sort(tst.begin(),tst.end());
//   int num=0;
//   do{
//     tr(tst,it){
//       cout<<*it<<" ";
//     }
//     cout<<endl;
//     num++;
//   }while(true);//while(std::next_permutation(tst.begin(),tst.end()));
//   cout<<'\n'<<num<<" permutations\n";
//
// }
void VecTest(){
  int m=5,n=5;
  vector< vector<int> >mat(m,vector<int>(n,12));
  std::vector<int> tst;

  // cout<<tst.size()<<"\t"<<tst.empty();
  tst.push_back(20);
  tst.push_back(19);
  tst.push_back(15);

  // cout<<mat.empty();
  // cout<<mat[0].size();
}

// ############# PAIRS & SET ###############
  // PAIR:-
  //   Compared from first, to last elements
  //   Can be used in place of any associative container
  // SET:-
  //   Doesnt allow duplicates
  //   Add,remove,Check in O(log N)
  //   * Global container .find() method - O(N)
  //   **For Set and Map, use set::find() and map::find() -- O(log N) !!
  //       - these return either iterator to element, or to end()
  // #####TO DEFINE MY OWN VERSION OF STL'S PAIR :
  // template<typename T1,typename T2> struct my_pair{
  //   T1 first;T2 second;
  // };
void PairTest(){
  pair<string, pair<int,int> > P;
  vector<pair<string,pair<int,int>>> v(3);

  for(int i=0;i<3;i++){
    pair<string, pair<int,int> > tmp;
    cin>>tmp.first>>tmp.second.first>>tmp.second.second;
    v[i]=tmp;
  }

  sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++){
    cout<<v[i].first<<": <"<<v[i].second.first<<","<<v[i].second.second<<">"<<"\n";
  }

  // double d=v[0].first;
  // int x=v[0].second.first;
  // int y=v[0].second.second;
  // cout<<d<<": <"<<x<<","<<y<<">";
}
void SetPairs(){
  set<pair<string,int> >s;
  set<pair<string,int> >::iterator it=s.begin();

  for(int i=0;i<2;i++){
    pair<string,int> tmp;
    cin>>tmp.first>>tmp.second;
    s.insert(tmp);
  }

  tr(s,it){
    cout<<(*it).first<<":"<<(*it).second<<'\n';
  }
  // pair<string,int>p("hello",2);
  // if(s.find(p)!=s.end())cout<<"found";
}

// #################### MAP ##################
 // Similar to set, but stores pair<key,value> instead
 // [] operator defined
 // Internally stored as Red-Black Trees
 // **Only stores UNIQUE keys

void MapTest(){
  map<string,int> M;
  M["a"]=10;M["d"]=7;
  M["c"]=6;M["b"]=1;
  map<string,int>::iterator it=M.begin();
  tr(M,it){
    cout<<it->first<<": "<<it->second<<"\n";
  }
}
void VecOfMaps(){
  vector<map<string,int>> V;
  // MAKE VECTOR OF MAPS ## each sorted separately!
  for(int j=0;j<2;j++){
    map<string,int>M;
    for(int i=0;i<2;i++){
      string str;int n;
      cin>>str>>n;
      M.insert(make_pair(str,n));
    }
    V.push_back(M);
  }

  vector<map<string,int>>::iterator it= V.begin();
  tr(V,it){
    map<string,int>::iterator tmp=(*it).begin();
    tr((*it),tmp){
      cout<<tmp->first<<":"<<tmp->second<<'\n';
    }
  }
}
void Map2Vec(){
  map<string,int>M;
  M["abc"]=15;M["gfh"]=33;
  M["xyz"]=17;M["pqr"]=21;

  // MAP ITERATORS CANT BE ADDED !

  std::vector<pair<string,int>> v(M.begin(),M.end());
  std::vector<pair<string,int>> v2(v.begin(),v.begin()+3);
  v.resize(v.size()+v2.size());

  // copy ( from_begin , from_end , to_begin )
  copy(v2.rbegin(),v2.rend(),v.end()-v2.size());

  for(int i=0;i<v.size();i++)cout<<v[i].first<<":"<<v[i].second<<'\n';

}

// #################### REFERENCE ##################

void SetOps(){
  int d1[] = { 0, 1, 2, 5, 6, 8, 9, 10 };
  int d2[] = { 0, 2, 3, 4, 7, 8, 10 };

  std::vector<int> v1(d1,d1+(sizeof(d1)/sizeof(d1[0])));
  std::vector<int> v2(d2,d2+(sizeof(d2)/sizeof(d2[0])));

  vector<int> tmp(max(v1.size(),v2.size()));
  int cnt=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),tmp.begin())-tmp.begin();

  std::vector<int>::iterator it=tmp.begin();
  tr(tmp,it){
    int n=*it;
    cout<<*it<<" ";
  }
  cout<<endl<<cnt;

}

int main(){
  // Map2Vec();
  SetOps();
}





















;
