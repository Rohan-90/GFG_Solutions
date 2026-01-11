class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int ans = 0, low = 0, high = 0, sum = 0;
        while(high < arr.size()) {
            while(high < arr.size() && high - low < k) {
                sum += arr[high];
                high++;
                
            }
            ans = max(ans,sum);
            sum -= arr[low];
            low++;
        }
        return ans;
    }
};