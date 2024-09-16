//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        int maxValidLength = 0, openCount = 0, closeCount = 0, maxValidLengthReverse = 0;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '(') openCount++;    
            else closeCount++;   
            
            if(closeCount > openCount) openCount = closeCount = 0;  
            else if(openCount == closeCount) maxValidLength = max(maxValidLength, openCount * 2); 
        }
        openCount = closeCount = 0;
        for(int i = str.length() - 1; i >= 0; i--) {
            if(str[i] == '(') openCount++;     
            else closeCount++;    
            
            if(openCount > closeCount) openCount = closeCount = 0; 
            else if(openCount == closeCount) maxValidLengthReverse = max(maxValidLengthReverse, openCount * 2);
        }
        return max(maxValidLength, maxValidLengthReverse);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends