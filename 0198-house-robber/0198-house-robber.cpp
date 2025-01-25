class Solution {
    int solve(int i,vector<int>&dp, vector<int>&nums,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int rob= nums[i]+ solve(i+2,dp,nums,n);
        int not_rob= 0+ solve(i+1,dp,nums,n);

        return dp[i]= max(rob,not_rob);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(0,dp,nums,n);
    }
};