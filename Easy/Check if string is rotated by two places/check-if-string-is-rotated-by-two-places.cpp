//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if(str1.size() != str2.size()) return false;
        string temp = str1;
        int n = str1.size();
        for(int i = 0; i < n; i++){
            temp[(i + 2) % n] = str1[i];
        }
        if(temp == str2) return true;
        
        string temp2 = str1;
        for(int i = 0; i < n; i++){
            temp2[i] = str1[(i + 2) % n];
        }
        if(temp2 == str2) return true;
        return false;
    }
};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends