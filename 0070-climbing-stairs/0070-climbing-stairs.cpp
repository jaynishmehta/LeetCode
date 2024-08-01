class Solution {
    int solve(vector<int>&dp,int i){
        if(i<=0){
            return 1;
        }
        if(dp[i]!=-1)return dp[i];
        
        int x= solve(dp,i-1);
        int y= 0;
        if(i>=2)
        {
           y= solve(dp,i-2);
        }
        return dp[i]=x+y;
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(dp,n);
    }
};