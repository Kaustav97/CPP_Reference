#include <bits/stdc++.h>
using namespace std;

#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int main(){
  string s="ababbbabbababa";
  // string s="ababbbabb";
  int len=s.size();

  std::vector<int> cut(len);
  std::vector<std::vector<bool> > palin(len,std::vector<bool>(len,0) );

  // palin[i][j] -> whether str[i:j] is a palindrome;
  // c[i] -> min cuts needed for palin partitioning of str[0:i]
  rep(len)palin[i][i]=1;

  int i,L,j;
  for (L=2; L<=len; L++){
      // For substring of length L, set different possible starting indexes
      for (i=0; i<len-L+1; i++){
          j = i+L-1; // Set ending index

          // If L is 2, then we just need to compare two characters. Else
          // need to check two corner characters and value of P[i+1][j-1]
          if (L == 2)
              palin[i][j] = (s[i] == s[j]);
          else
              palin[i][j] = (s[i] == s[j]) && palin[i+1][j-1];
      }
  }

  for(int i=0;i<len;i++){
    for(int j=0;j<len;j++)cout<<palin[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;
  //  ababb
  for(int i=0;i<len;i++){
    if(palin[0][i])cut[i]=0;
    else{
      cut[i]=INT_MAX;
      for(int j=0;j<i;j++){
        if(palin[j+1][i] == true && 1+cut[j]<cut[i]) cut[i]=1+cut[j];
      }
    }
  }

  tr1(cut)cout<<*it<<" ";
  cout<<endl;

  // cout<<cut[len-1]<<endl;
}
