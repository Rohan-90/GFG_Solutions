//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GfG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int m = sc.nextInt();
            int n = sc.nextInt();
            int points[][] = new int[m][n];
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++) points[i][j] = sc.nextInt();
            Solution ob = new Solution();
            System.out.println(ob.minPoints(points, m, n));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
   public int minPoints(int points[][], int n, int m) {
        // Your code goes here
        int[][] memo = new int[n][m];
        for (int[] row : memo) {
            Arrays.fill(row, Integer.MIN_VALUE);
        }
          return dfs(0,0,points,n,m, memo);
    }
    int dfs(int i, int j, int arr[][], int n, int m, int[][] memo){
        if(i==n-1 && j==m-1)
        return arr[i][j] > 0 ? 1 : Math.abs(arr[i][j])+1;
        
          if (memo[i][j] != Integer.MIN_VALUE)
            return memo[i][j];

        int ans = Integer.MAX_VALUE;
        //2 calls
        //right , i , j+1
        if(j+1<m){
        int x = - arr[i][j] + dfs(i, j+1, arr, n,m, memo);
        ans = Math.min(ans,x);
        }
        
        //down i+1, j
        if(i+1 < n){
        int y =  - arr[i][j] + dfs(i+1, j, arr, n,m, memo);
         ans = Math.min(ans,y);
        }
         memo[i][j] = ans <= 0 ? 1 : ans;
      return memo[i][j];
    }
}