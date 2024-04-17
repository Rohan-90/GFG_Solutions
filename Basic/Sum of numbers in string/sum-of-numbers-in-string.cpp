//{ Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string s)
    {
        
        int sum = 0;
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])) temp += s[i];
            else if(!temp.empty()) {
                sum += stoi(temp);
                temp = "";
            }
        }
        if(!temp.empty()) sum += stoi(temp);
    	return sum;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}

// } Driver Code Ends