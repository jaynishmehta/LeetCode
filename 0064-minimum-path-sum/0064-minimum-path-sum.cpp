class Solution {
//     int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid){
//         if(i<0 || j<0)return 5200;
//         if(i==0 && j==0)return grid[i][j];
        
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         int down=0,left=0;
//          down = grid[i][j]+solve(i-1,j,dp,grid);
//          left =grid[i][j]+solve(i,j-1,dp,grid);
        
//         return dp[i][j]=min(down,left);
//     }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        vector<vector<int>>dp(200,vector<int>(201,0));
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)dp[0][0]=grid[0][0];
                else{
                    int down = INT_MAX, left = INT_MAX;
                     if(j>0)
                         left =grid[i][j]+dp[i][j-1];
                    if(i>0)
                        down = grid[i][j]+dp[i-1][j];
                    dp[i][j]=min(down,left);

                }
            }
        }
        return dp[n-1][m-1];
        
        // return solve(n-1,m-1,dp,grid);
    }
};