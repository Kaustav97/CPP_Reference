#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(it;it!=cont.end();it++)

int comp(pair<int,int> &a,pair<int,int> &b){
  float s1=a.second/(a.first*1.0);
  float s2=b.second/(b.first*1.0);

  if(s1>s2)return 1;
  else return 0;
}

double speed(std::vector<pair<int,int> > &v){
  sort(v.begin(),v.end(),comp);

  int len=v.size();
  double score=1000;
  for(int i=0,j=v.size()-1;i<j;i++,j--){
    double nscore= (v[i].second+v[j].second)/(v[i].first+v[j].first+20.0);
    if(nscore<score)score=nscore;
  }

  // double score= (v[len/2].second+v[len/2+1].second)/(v[len/2].first+v[len/2+1].first+20.0);

  return score;

  // tr1(v)cout<<it->first<<","<<it->second<<endl;
}

int main(){
  int n;cin>>n;
  std::vector<pair<int,int> > ppl(n);
  for(int i=0;i<n;i++){
    int si,wi;
    cin>>wi>>si;
    ppl[i]=make_pair(wi,si);
  }

  // ppl.push_back(make_pair(50,50));
  // ppl.push_back(make_pair(50,60));
  // ppl.push_back(make_pair(70,100));
  // ppl.push_back(make_pair(100,60));

  cout<<speed(ppl);

  // tr1(ppl)cout<<it->first<<","<<it->second<<endl;

}
