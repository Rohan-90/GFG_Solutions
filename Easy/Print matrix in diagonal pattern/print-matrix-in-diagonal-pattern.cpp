//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
       vector<int> result;
    int n = mat.size(); // Since the matrix is n*n

    int row = 0, col = 0;
    // Direction indicates the movement: 1 for up-right, -1 for down-left
    int direction = 1;

    for (int i = 0; i < n * n; ++i) {
        result.push_back(mat[row][col]);

        // Moving up-right
        if (direction == 1) {
            if (col == n - 1) { // If we are at the last column, move down and change direction
                row++;
                direction = -1;
            } else if (row == 0) { // If we are at the first row, move right and change direction
                col++;
                direction = -1;
            } else { // Otherwise, move up-right
                row--;
                col++;
            }
        }
        // Moving down-left
        else {
            if (row == n - 1) { // If we are at the last row, move right and change direction
                col++;
                direction = 1;
            } else if (col == 0) { // If we are at the first column, move down and change direction
                row++;
                direction = 1;
            } else { // Otherwise, move down-left
                row++;
                col--;
            }
        }
    }

    return result;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends