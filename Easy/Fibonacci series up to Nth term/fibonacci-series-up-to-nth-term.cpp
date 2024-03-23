//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9 + 7;
    void solve(int n, vector<int>& ans) {
     if (n == 0) {
            ans.push_back(0);
            return;
        } else if (n == 1) {
            ans.push_back(0);
            ans.push_back(1);
            return;
        }
        if (ans.size() < n) {
            solve(n-1, ans);
            int nextNum = ((ans[ans.size() - 1] % mod) + (ans[ans.size() - 2] % mod)) % mod;
            ans.push_back(nextNum);
        }
    }
    vector<int> Series(int n) {
        vector<int> ans;
        solve(n,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends