// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int low = 0;
        for(int high = 0; high < arr.size(); high++) {
            if(arr[high] == 1) {
                low = high;
                break;
            } 
        }
        for(int high = low + 1; high < arr.size(); high++) {
            if(arr[high] == 0) {
                swap(arr[high], arr[low]);
                low++;
            }
        }
    }
};