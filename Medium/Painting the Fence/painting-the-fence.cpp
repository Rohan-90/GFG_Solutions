//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long dpMemo(int n, int k , vector<int> & dp){
        long long mod = 1000000007;
        if(n == 1) return k;
        if(n == 2) return (k*k)% mod;
        if(dp[n] != -1) return dp[n];
        return dp[n] = ((k-1) % mod)* (dpMemo(n-1, k, dp)% mod + dpMemo(n-2, k, dp)% mod)% mod;
    }
    long long solve(int n, int k){
        long long mod = 1000000007;
        if(n == 1) return k;
        if(n == 2) return (k*k)% mod;
        long long count  = ((k-1) % mod)* (solve(n-1, k)% mod + solve(n-2, k)% mod)% mod;
        return count;
    }
    long long countWays(int n, int k){
        vector<int> dp(n+1, -1);
        return dpMemo(n,k,dp);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends