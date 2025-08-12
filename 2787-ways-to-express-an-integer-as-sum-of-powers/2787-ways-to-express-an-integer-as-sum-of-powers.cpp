class Solution {
public:
    int mode = 1e9+7;
    int f(int num,int n,int x,vector<vector<int>>&dp){
        if(n==0)return 1;
        if(n<0)return 0;
        if(pow(num,x)>n)return 0;
        
        if(dp[num][n]!=-1)return (dp[num][n]%mode);
        int nottake= f(num+1,n,x,dp);
        int take=f(num+1,n-pow(num,x),x,dp);
        return dp[num][n]=(take+nottake)%mode;
    }

    int numberOfWays(int n, int x) {
        // vector<vector<int>>dp(pow(n, 1.0 / x)+1,vector<int>(n+1,-1));
        vector<vector<int>>dp(301,vector<int>(301,-1));
        return f(1,n,x,dp)%mode;
    }
};