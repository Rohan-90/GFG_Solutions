//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string A) {
        stack<char> st;
        for(int i = 0; i < A.length(); i++){
        if(A[i] == '(' || A[i] == '+' || A[i] == '*' || A[i] == '/' || A[i] == '-') st.push(A[i]);
        else if(A[i] == ')'){
            int countOperator = 0;
            while(!st.empty() && st.top() != '('){
                if(st.top() == '+' || st.top() == '*' || st.top() == '/' || st.top() == '-') countOperator++;
                st.pop();
            }
            st.pop();
            if(countOperator == 0) return true;
        }
    }
    return false;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends