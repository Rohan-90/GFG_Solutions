//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
        int q) {
        int maxi = -1;
        maxi = *max_element(b.begin(), b.end());
        vector<int> k(maxi + 1, 0);
        for(int i = 0; i < n; i++) k[b[i]]++;
        for(int i = 1; i <= maxi; i++){
            k[i] += k[i-1];
        }
        vector<int> ans;
        for(int i = 0; i < q; i++){
            if(a[query[i]] > maxi) ans.push_back(n);
            else ans.push_back(k[a[query[i]]]);
        }
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
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends