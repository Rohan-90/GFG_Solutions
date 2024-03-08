//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    bool check(vector<int>& vec){
        int n = -1;
        for(auto it : vec){
            if(it > 0){
                if(n == -1) n = it;
                else if( it != n) return false;
            }
        }
        return true;
    }
	bool sameFreq(string s)
	{
	   vector<int> vec(26,0);
	   for(auto it : s){
	       int ch = it - 'a';
	       vec[ch]++;
	   }
	   if(check(vec)) return true;
	   
	   for(int  i = 0; i < 26; i++){
	        if(vec[i] > 0){
	             vec[i]--;
	             if(check(vec)) return true;
	             vec[i]++;
	        } 
	   }
	   return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends