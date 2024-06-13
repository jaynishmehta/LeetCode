class Solution {
    //WHEN LIMIT EXCEEDS WE RETURN INT_MAX INSTEAD TO 0;
    int f(int m,int n,vector<vector<int>>& grid,int row,int col,vector<vector<int>>&dp){
        if(row==m-1 && col==n-1){
            return grid[row][col];
        }
        if(row>=m || col>=n)return INT_MAX;
        if(dp[row][col]!=-1)return dp[row][col];
        
        int right = (col+1<n)? grid[row][col]+f(m,n,grid,row,col+1,dp):INT_MAX;
        int down = (row+1<m)? grid[row][col]+f(m,n,grid,row+1,col,dp):INT_MAX;
        
       
        return dp[row][col]=min(right,down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        // int sum=0;
        int m= grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(200,vector<int>(201,-1));  //dp-1
        return f(m,n,grid,0,0,dp);
    }
};