#include <bits/stdc++.h>
using namespace std;

#define nl cout<<endl;
#define disp(x) for(auto val:x)cout<<val<<" "; nl

bool decide(int x){
  return (x%2==1);
}

int main(){
  std::vector<int> nums{1,2,3,4,5,6,7,8,9};
  shuffle(begin(nums),end(nums),default_random_engine(0));
  std::vector<int> org= nums;

  //  SORTING - PARTITIONING
  make_heap(begin(nums),end(nums));
  nums.push_back(15);
  push_heap(begin(nums),end(nums));
  pop_heap(begin(nums),end(nums));nums.pop_back();


  shuffle(begin(nums),end(nums),default_random_engine(0));

  partial_sort(begin(nums),begin(nums)+3,end(nums));
  nth_element(begin(nums),begin(nums)+4,end(nums));

  auto bg= begin(nums),ed = end(nums);

  sort(bg,bg+3);
  sort(bg+3,ed);
  for(int x:nums)cout<<x<<" "; cout<<endl;
  inplace_merge(bg,bg+3,ed);
  for(int x:nums)cout<<x<<" "; cout<<endl;


  // PARTITIONING

  nums=org;
  shuffle(begin(nums),end(nums),default_random_engine(0));
  for(int x:nums)cout<<x<<" "; nl
  auto brk = stable_partition(begin(nums),end(nums),decide);
  auto it1=begin(nums);
  for(it1 = begin(nums);it1!=brk;it1++)cout<<(*it1)<<" "; nl
  while(it1!=end(nums)){cout<<(*it1)<<" "; it1++;}
  nl
  cout<<(is_partitioned(begin(nums),end(nums),decide)?"IS":"NOT")<<endl;
  cout<<"UNTIL - "<<(partition_point(begin(nums),end(nums),decide) - begin(nums));


  // PERMUTATIONS:

  rotate(begin(nums),begin(nums)+2,end(nums));

  std::vector<int> nums2= std::vector<int> (begin(nums),begin(nums)+4);
  // sort(begin(nums2),end(nums2) );
  shuffle(begin(nums2),end(nums2),default_random_engine(0));
  for(int x:nums2)cout<<x<<" "; nl;
  while(next_permutation(begin(nums2),end(nums2))){
    for(int x:nums2)cout<<x<<" "; nl;
  }


  // LAMBDAS:

  shuffle(begin(nums),end(nums),default_random_engine(0));
  cout<<"COEFFS: \t"; for(int x:nums) cout<<x<<" "; nl

  std::vector<int> wgts(nums);
  shuffle(begin(wgts),end(wgts),default_random_engine(0));
  cout<<"WEIGHTS: \t";
  for(int x:wgts)cout<<x<<" "; nl

  int ptr=0;
  cout<<"AVERAGE: \t"<< accumulate(begin(nums),end(nums),0.0f, [&wgts,&ptr](int x,int y){
    return x+wgts[ptr++]*y;
  })/nums.size()<<endl;


  srand(time(0));
  std::vector<int> v1,v2;
  for(int i=0;i<15;i++)v1.push_back( rand()*1.0/RAND_MAX *100.0 ) ;
  disp(v1);

  // AGGREGATE FUNCTIONS

  transform(begin(v1),end(v1),back_inserter(v2),[](int x){
    return x%12;
  } );
  disp(v2);

  disp(nums);
  cout<<any_of(begin(nums)+2,begin(nums)+5,[](int x){
    return x%3;
  } )<<endl;

  std::vector<int> tst(begin(nums),end(nums)-3);
  shuffle(begin(tst),end(tst),default_random_engine(151));
  shuffle(begin(nums),end(nums),default_random_engine(12));
  disp(tst);disp(nums);
  // cout<<is_permutation(begin(tst),end(tst)-2,&nums[0])<<endl;
  cout<<lexicographical_compare(begin(tst),end(tst)-3,begin(nums),end(nums))<<endl;

  disp(nums);
  std::vector<float> diffs(nums.size(),0.0f);
  adjacent_difference(begin(nums),end(nums),&diffs[0],[](int val,int prev){
    return (val*1.0)/prev;
  } );
  disp(diffs);


  // RANGE QUERIES

  std::vector<int> dst;
  for(int i=1;i<=25;i++)dst.push_back(i);
  shuffle(begin(dst),end(dst),default_random_engine(15));
  std::vector<int> patt={10,4,23};
  disp(dst);
  find_first_of(begin(dst),end(dst),begin(patt),end(patt))-begin(dst);
  search(begin(dst),end(dst),begin(patt),end(patt))-begin(dst);


  //  SET OPERATIONS

  std::vector<int> v1,v2,res;
  for(int i=1;i<=25;i++)v1.push_back(i);
  shuffle(begin(v1),end(v1),default_random_engine(0));
  v2=std::vector<int>(begin(v1),begin(v1)+12);

  sort(begin(v1),end(v1)); sort(begin(v2),end(v2));
  disp(v1);disp(v2);
  nl
  set_union(begin(v1),end(v1),begin(v2),end(v2),back_inserter(res) );
  set_intersection(begin(v1),end(v1),begin(v2),end(v2),back_inserter(res) );
  set_symmetric_difference(begin(v1),end(v1),begin(v2),end(v2),back_inserter(res) );
  disp(res);






}
