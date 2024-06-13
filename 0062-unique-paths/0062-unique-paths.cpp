class Solution {
     int f(int m, int n, int row, int col,vector<vector<int>>&dp) {
        if(row == m-1 && col == n-1) {
            return 1;
        }
        if(row >= m || col >= n) {
            return 0;
        }
        if(dp[row][col]!=-1)return dp[row][col];
         
        // Move right and down
        int right = f(m, n, row, col + 1,dp);
        int down = f(m, n, row + 1, col,dp);
        
        return dp[row][col]= right + down;
    }
public:
    int uniquePaths(int m, int n) {
        int ans;
        vector<vector<int>>dp(100,vector<int>(101,-1));
        return f(m,n,0,0,dp);
    }
};