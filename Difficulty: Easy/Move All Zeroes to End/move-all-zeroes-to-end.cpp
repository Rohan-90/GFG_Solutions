class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i = -1;
        for(int k = 0; k < n; k++) {
            if(arr[k] == 0){
                i = k; //spot zero first 
                break;
            } 
        }
        if(i == -1) return;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] != 0) {
                swap(arr[j], arr[i]);
                i++;
            } 
            else continue;
        }
    }
};