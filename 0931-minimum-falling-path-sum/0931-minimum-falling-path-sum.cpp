class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row= matrix.size();
        int col = matrix[0].size();
        vector<vector<int>>dp(100,vector<int>(101,-1));
        
        for(int j=0;j<col;j++)dp[0][j]=matrix[0][j];
        
        for(int i=1;i<row;i++){
            for(int j=0;j<col;j++){
                int d  = matrix[i][j]+dp[i-1][j];
                int lf = (j-1>=0)?matrix[i][j]+dp[i-1][j-1]:1e7;
                int rf = (j+1<col)?matrix[i][j]+dp[i-1][j+1]:1e7;
                
                dp[i][j]=min(d, min(lf,rf));
            }
        }
        
        // retriving min element from the 0th row from the dp;
        int mini= 1e7;
        for(int i=0;i<col;i++){
            mini=min(mini,dp[row-1][i]);
        }
        return mini;
    }
};