//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:

bool solve(string &wild, string &pattern, int n, int m, vector<vector<int>> &dp){
        if(m == 0 && n == 0) return true;
        if(m > 0 && n == 0){
            for(int  i = 0 ; i < m; i++){
                if(wild[i] != '*') return false;
            }
            return true;
        }
        if(m == 0 && n > 0) return false;
        if(dp[n][m] != -1) return dp[n][m];

        if(wild[m-1] == pattern[n-1] || wild[m-1] == '?') return dp[n][m] = solve(wild, pattern, n - 1, m - 1, dp);
        else if(wild[m-1] == '*') return dp[n][m] = solve(wild, pattern, n - 1, m, dp) || solve(wild, pattern, n , m - 1, dp);
        return dp[n][m] = false;
    }

bool match(std::string wild, std::string pattern) {
    int n = pattern.size();
    int m = wild.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, -1));
    return solve(wild, pattern, n, m, dp);
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends