//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int cubeRoot(int N) {
        int ans = 0;
        long long low  = 0;
        long long high = N;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(mid * mid * mid <= N){
                ans = mid;
                low = mid + 1; 
            } 
            else if(mid * mid * mid > N) high = mid -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.cubeRoot(N) << endl;
    }
    return 0;
}
// } Driver Code Ends