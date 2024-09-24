//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int strLength = s.length(), patLength = p.length(), windowStart = -1, windowEnd = -1, minLength = INT_MAX, uniqueCharsInPattern = 0, uniqueCharsInWindow = 0, left = 0;
        vector<int> charCountInString(26, 0), charCountInPattern(26, 0);
        for(int i = 0; i < patLength; i++) {
            charCountInPattern[p[i] - 'a']++;
            if (charCountInPattern[p[i] - 'a'] == 1) uniqueCharsInPattern++;
        }
        for(int right = 0; right < strLength; right++) {
            charCountInString[s[right] - 'a']++;
            if (charCountInString[s[right] - 'a'] == charCountInPattern[s[right] - 'a']) uniqueCharsInWindow++;
            if (uniqueCharsInWindow == uniqueCharsInPattern) {
                while (charCountInString[s[left] - 'a'] > charCountInPattern[s[left] - 'a']) charCountInString[s[left++] - 'a']--;
                if (minLength > right - left + 1) {
                    windowStart = left;
                    windowEnd = right;
                    minLength = right - left + 1;
                }
            }
        }
        if (windowStart == -1) return "-1";
        return s.substr(windowStart, minLength);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends