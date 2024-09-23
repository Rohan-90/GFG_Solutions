//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int i = 0, repeat = -1, missing = -1;
        while (i < arr.size()) {
            int correct = arr[i] - 1;  
            if (arr[i] != arr[correct]) swap(arr[i], arr[correct]);
            else i++;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != i + 1) {
                repeat = arr[i];
                missing = i + 1;
            }
        }
        return {repeat, missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends