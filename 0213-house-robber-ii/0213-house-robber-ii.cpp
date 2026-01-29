class Solution {
    int solve(vector<int>&dp,int i,int j,vector<int>nums){
        if(i>j)return 0;
        if(dp[i]!=-1)return dp[i];
        int take= nums[i]+solve(dp,i+2,j,nums);
        int nottake= solve(dp,i+1,j,nums);
        return dp[i]= max(take,nottake);
    }
public:

    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(nums.size()+1,-1);
        vector<int>dp2(nums.size()+1,-1);
        return max(solve(dp1,0,n-2,nums),solve(dp2,1,n-1,nums));
    }
};