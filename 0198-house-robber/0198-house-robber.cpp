class Solution {
    int solve(vector<int>& nums,vector<int>&dp,int i){
        if(i<0)return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        int take= nums[i]+solve(nums,dp,i-2);
        int nottake= 0+solve(nums,dp,i-1);
        return dp[i]=max(take,nottake);
    }
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,dp,n-1);
    }
};