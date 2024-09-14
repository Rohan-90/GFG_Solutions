//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        vector<int> posi, neg;
        for (int num : arr) {
            if (num >= 0) posi.push_back(num);
            else neg.push_back(num);
        }
        int posIndex = 0, negIndex = 0, i = 0;
        int n = arr.size();
    
        while (posIndex < posi.size() && negIndex < neg.size()) {
            if (i % 2 == 0) arr[i++] = posi[posIndex++];
            else arr[i++] = neg[negIndex++];
        }
        while (posIndex < posi.size()) arr[i++] = posi[posIndex++];
        while (negIndex < neg.size()) arr[i++] = neg[negIndex++];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends