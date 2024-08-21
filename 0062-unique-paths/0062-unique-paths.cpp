class Solution {
    int f(int row,int col,vector<vector<int>>&dp){
        if(row==0 && col==0)return 1;
        if(row<0 || col<0)return 0;
        
        if(dp[row][col]!=-1)return dp[row][col];
        
        int top=0,left=0;
        top= f(row-1,col,dp);
        left= f(row,col-1,dp);
        
        return dp[row][col]= top+left;
        
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n+1,-1));
        return f(m-1,n-1,dp);
    }
};