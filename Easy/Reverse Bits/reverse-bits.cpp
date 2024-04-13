//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long solve(vector<int>& a){
      long long ans = 0;
      int j = 0;
      for(int i = 31; i >= 0; i--){
          if(a[i] != 0) ans += pow(2,j);
          j++;
      }
      return ans;
  }
    long long reversedBits(long long x) {
        vector<int> a(32,0);
        vector<int> b;
        int i = 0;
        while(x){
            if(x % 2 == 0) a[i] = 0;
            else a[i] = 1;
            x = x / 2;
            i++;
        }
        long long ans = solve(a); 
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends