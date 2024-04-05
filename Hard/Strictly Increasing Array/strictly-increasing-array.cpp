//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int>& nums){
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && nums[i] - nums[j] >= i - j) dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        int ans = 0;
        for(auto &it : dp) ans = max(ans,it);
        
        return abs(nums.size() - ans);
    }
    int min_operations(vector<int>& nums) {
        return solve(nums);
       
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends