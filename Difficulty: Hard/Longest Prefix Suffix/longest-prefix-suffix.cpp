//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        int i = 1, j = 0;
        vector<int> s(str.length(), 0);
        while(i < str.length()){
            if(str[i] == str[j]) s[i++] = ++j;
            else{
                if(j > 0) j = s[j-1];
                else i++;
            }
        }
        return s[str.length() - 1];
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends