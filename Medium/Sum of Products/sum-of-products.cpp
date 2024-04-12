//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
       long long sum = 0;
    // Each integer is at most 108, so we need to consider bits up to 2^27
    for (int bit = 0; bit < 30; bit++) {
        long long count = 0;
        // Count how many numbers have the current bit set
        for (int i = 0; i < n; i++) {
            if (arr[i] & (1 << bit)) {
                count++;
            }
        }
        // Now calculate the contribution from all pairs that can be formed with this bit set
        sum += ((1LL << bit) * (count * (count - 1) / 2));
    }
    return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends