class Solution {
    bool solve(int i,int t,int sum,vector<int>&n,vector<vector<int>>&dp){
        if(i>=n.size())return (t==sum);

        if(dp[i][t]!=-1)return dp[i][t];

        // bool take=false;
        // if(t+n[i]<=sum){
            bool take = solve(i+1,t+n[i],sum-n[i],n,dp);
        // }
        bool nottake= solve(i+1,t,sum,n,dp);
        return dp[i][t]= take || nottake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum &1)return false;
        vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
        return solve(0,0,sum,nums,dp);
    }
};