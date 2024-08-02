class Solution {
    int solve(int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0)return 0;
        if(i==0 && j==0){
            return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        int right=0,down=0;
        if(j>0){
            right= solve(i,j-1,dp);
        }
        if(i>0){
            down = solve(i-1,j,dp);
        }
        return dp[i][j]= right+down;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n+1,-1));
        return solve(m-1,n-1,dp);
    }
};