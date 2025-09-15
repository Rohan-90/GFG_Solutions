

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        int maxNum = arr[n - 1];
        ans.push_back(maxNum);//last index number is always in the result
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] >= maxNum) {
                ans.push_back(arr[i]);
                maxNum = arr[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};