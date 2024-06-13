class Solution {
    int f(int m,int n,vector<vector<int>> & grid,int row,int col,vector<vector<int>>&dp){
        if(grid[row][col]==1)return 0;
        if(row == m-1 && col==n-1)return 1;
        // if(row>=m || col>=n)return 0;
        
        if(dp[row][col]!=-1)return dp[row][col];
        int right = (col + 1 < n) ? f(m, n, grid, row, col + 1,dp) : 0;  //checking before accessing the element to reduce the error
        int down = (row + 1 < m) ? f(m, n, grid, row + 1, col,dp) : 0;
        
        return dp[row][col] = right+down;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(100,vector<int>(101,-1));
        return f(m,n,grid,0,0,dp);
    }
};