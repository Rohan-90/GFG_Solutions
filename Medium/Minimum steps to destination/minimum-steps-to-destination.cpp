//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minSteps(int d) {
       int ans = 0, temp = 0;
       while(temp < d){
           ans++;
           temp += ans;
       }
        if(temp == d) return ans;
        int diff = temp - d;
        if(diff % 2 == 0) return ans;
        if(ans % 2 == 0) return ans + 1;
        else return ans + 2;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends