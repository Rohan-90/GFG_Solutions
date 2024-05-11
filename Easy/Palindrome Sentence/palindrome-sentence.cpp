//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sentencePalindrome(string s) 
	{
	    // code here
	    int st = 0;
	    int e = s.size() - 1;
	    while(e >= st){
	        if((s[st] >= 'a' && s[st] <= 'z') && (s[e] >= 'a' && s[e] <= 'z') && s[st] == s[e]){
	            st++;
	            e--;
	        }
	        else if((s[st] >= 'a' && s[st] <= 'z') && !(s[e] >= 'a' && s[e] <= 'z')) e--;
	        else if( !(s[st] >= 'a' && s[st] <= 'z') && (s[e] >= 'a' && s[e] <= 'z')) st++;
	        else if((s[st] >= 'a' && s[st] <= 'z') && (s[e] >= 'a' && s[e] <= 'z') && s[st] != s[e]) return false;
	        else{
	            st++;
	            e--;
	        }
	    }
	    return true;
	}
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        Solution ob;
        cout<<ob.sentencePalindrome(str)<<endl;
    }
    return 0;
}  


// } Driver Code Ends