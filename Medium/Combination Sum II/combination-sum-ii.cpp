//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(vector<int>& arr,int n,int k, int i, int sum, vector<int>& temp, set<vector<int>>& s){
        if(sum == k){
            s.insert(temp);
            return;
        }
        if(i >= arr.size()) return;
        solve(arr, n, k, i + 1, sum, temp, s);
        if(arr[i] + sum <= k){
            temp.push_back(arr[i]);
            solve(arr, n, k, i + 1, sum + arr[i], temp, s);
            temp.pop_back();
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        sort(arr.begin(), arr.end());
        vector<int> temp;
        set<vector<int>> s;
        solve(arr, n, k, 0, 0, temp, s);
        vector<vector<int>> v(s.begin(), s.end());
        return v;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends