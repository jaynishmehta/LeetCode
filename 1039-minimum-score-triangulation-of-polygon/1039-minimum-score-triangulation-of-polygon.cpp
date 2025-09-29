class Solution {
    int solve(int i,int j,vector<int>& values,vector<vector<int>>&dp){
        if(i+1==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int sum=INT_MAX;
        for(int k=i+1;k<j;k++){
            sum= min(sum,values[i]*values[j]*values[k]+solve(i,k,values,dp)+solve(k,j,values,dp));
        }
        dp[i][j]=sum;
        return dp[i][j];
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n= values.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,values.size()-1,values,dp);
    }
};