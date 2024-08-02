class Solution {
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& grid){
        if(i<0 || j<0)return 0;
        if(i==0 && j==0){
            if(grid[i][j]==1)return 0;
            else return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        int right=0,down=0;
        if(j>0 && grid[i][j]!=1){
            right= solve(i,j-1,dp,grid);
        }
        if(i>0 && grid[i][j]!=1){
            down = solve(i-1,j,dp,grid);
        }
        return dp[i][j]= right+down;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n+1,-1));
        return solve(m-1,n-1,dp,grid);
    }
};