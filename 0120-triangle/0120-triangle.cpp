class Solution {
    int solve(int i,int j, vector<vector<int>>&dp, vector<vector<int>>&t,int n,int m){
        if(i>n || j>m)return 1e5;
        if(i==n)return t[i][j];
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int right=1e5,left=1e5;
        right= t[i][j]+solve(i+1,j+1,dp,t,n,m);
        left= t[i][j]+solve(i+1,j,dp,t,n,m);
        
        return  dp[i][j] = min(right,left);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return solve(0,0,dp,triangle,n-1,m-1);
    }
};