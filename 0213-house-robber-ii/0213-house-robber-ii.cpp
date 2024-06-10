class Solution {
    int f(int i,int end,vector<int>&nums,vector<int>&dp){
        if(i>end)return 0;
        if(dp[i]!=-1)return dp[i];
        
        int pick= nums[i]+f(i+2,end,nums,dp);
        int not_pick =f(i+1,end,nums,dp);
         
        return dp[i] = max(pick,not_pick);
    }
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(101,-1);
        vector<int>dp2(101,-1);
        int include=f(0,n-2,nums,dp1);
        int exclude=f(1,n-1,nums,dp2);
        return max(include,exclude);
    }   
};