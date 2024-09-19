//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        string ans = "";
        int i = 0;
        while(i < str.size()) {
            int j = i;
            while(j < str.size() && str[j] != '.') j++;
            while(i < str.size() && str[i] == '.') i++;
            string part = str.substr(i, j - i);
            if(ans.size() == 0) ans += part;
            else ans = part +"." + ans;
            i = j + 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends