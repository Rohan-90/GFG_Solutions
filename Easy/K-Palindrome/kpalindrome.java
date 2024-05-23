//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while (t-- > 0) {
            String input_line[] = in.readLine().trim().split("\\s+");
            int n = Integer.parseInt(input_line[0]);
            int k = Integer.parseInt(input_line[1]);
            String str = in.readLine();

            Solution ob = new Solution();
            System.out.println(ob.kPalindrome(str, n, k));
        }
    }
}
// } Driver Code Ends


class Solution {
   public int lcs(String s, String r, int i, int j, int [][] dp) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s.charAt(i) == r.charAt(j)) 
            return dp[i][j] = 1 + lcs(s, r, i - 1, j - 1, dp);
        
        dp[i][j] = Math.max(lcs(s, r, i - 1, j, dp), lcs(s, r, i, j - 1, dp));
        return dp[i][j];
    }

    public int kPalindrome(String str, int n, int k) {
        StringBuilder r = new StringBuilder(str);
        r.reverse();
        int[][] dp = new int[n][n];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        int ans = lcs(str, r.toString(), n - 1, n - 1, dp);
        int rem = n - ans;
        return rem <= k ? 1 : 0;
    }
}