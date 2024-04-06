//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to count number of ways to reach the nth stair
   /* int solve(int n, int i, vector<int>& dp){
        if(i == n) return 1;
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];
        dp[i] = solve(n, i + 1, dp) + solve(n, i + 2, dp);
        return dp[i];
    }*/
    // when order does not matter.
    long long countWays(int n) {
       return (n/2)+1;
        
    }
};

//{ Driver Code Starts.
int main() {
    // taking count of testcases
    int t;
    cin >> t;

    while (t--) {
        // taking stair count
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countWays(n) << endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends