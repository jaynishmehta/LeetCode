class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size()-1)return 0;
        if(dp[i]!=100001)return dp[i];

        for(int pos=1;pos<=nums[i];pos++){
            int ans = solve(i+pos,nums,dp);
            dp[i]=min(dp[i],1+ans);
        }
        return dp[i];
    }

    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),100001);
        return solve(0,nums,dp);
    }
};