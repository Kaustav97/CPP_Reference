#include <bits/stdc++.h>

using namespace std;
#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr1(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)
#define MOD 998244353
#define ll long long
#define fs first
#define sc second

// dp[i][j] is going to store true if sum j is
// possible with array elements from 0 to i.
bool** dp;
std::vector<std::vector<int> > subs;
void printSubsetsRec(int arr[], int i, int sum, vector<int>& p){
    if (i == 0 && sum != 0 && dp[0][sum])
    {
        p.push_back(arr[i]);
        // display(p);
        subs.push_back(p);
        return;
    }

    // If sum becomes 0
    if (i == 0 && sum == 0)
    {
        // display(p);
        subs.push_back(p);
        return;
    }

    // If given sum can be achieved after ignoring
    // current element.
    if (dp[i-1][sum])
    {
        // Create a new vector to store path
        vector<int> b = p;
        printSubsetsRec(arr, i-1, sum, b);
    }

    // If given sum can be achieved after considering
    // current element.
    if (sum >= arr[i] && dp[i-1][sum-arr[i]])
    {
        p.push_back(arr[i]);
        printSubsetsRec(arr, i-1, sum-arr[i], p);
    }
}
void printAllSubsets(int arr[], int n, int sum){
    if (n == 0 || sum < 0)
       return;

    // Sum 0 can always be achieved with 0 elements
    dp = new bool*[n];
    for (int i=0; i<n; ++i)
    {
        dp[i] = new bool[sum + 1];
        dp[i][0] = true;
    }

    // Sum arr[0] can be achieved with single element
    if (arr[0] <= sum)
       dp[0][arr[0]] = true;

    // Fill rest of the entries in dp[][]
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < sum + 1; ++j)
            dp[i][j] = (arr[i] <= j) ? dp[i-1][j] ||
                                       dp[i-1][j-arr[i]]
                                     : dp[i - 1][j];
    if (dp[n-1][sum] == false)
    {
        printf("There are no subsets with sum %d\n", sum);
        return;
    }

    // Now recursively traverse dp[][] to find all
    // paths from dp[n-1][sum]
    vector<int> p;
    printSubsetsRec(arr, n-1, sum, p);
}

ll opt_ncr(int N,int R){
  ll ans=1;
  int tmp=R;

  while(R>=1){
    ans= (ans *(N--) )%MOD;
    ans/=(R--);
  }

  return ans;
}

ll Catalan(int R){
  int N=2*R;
  return (opt_ncr(N,R)) %MOD / ((R+1)%MOD);
}


// Driver code
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 10;
    printAllSubsets(arr, n, sum);

    cout<<Catalan(99999)<<endl;

    return 0;
}
