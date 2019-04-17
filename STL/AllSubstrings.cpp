#include <iostream>
#include <vector>

using namespace std;

#define tr2(cont,it) for(it;it!=cont.end();it++)
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)

void AllSubs(string a,string b){
  // leaf
  if(a.empty()){
    cout<<b<<endl;
    return;
  }
  char beg=a[0];
  a.erase(a.begin());

  // cout<<a<<" | "<<b<<endl;

  // exclude first
  AllSubs(a,b);

  // // include first
  b.push_back(beg);
  AllSubs(a,b);
}

int main(){
  AllSubs("abcd","");

}
