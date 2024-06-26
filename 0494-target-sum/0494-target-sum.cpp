//this question can be solve using  as number of subsets(s1,s1) whose abs(diff) is equal to target (dp-18 striver)
class Solution {
    int f(int i,int s,vector<int>&nums,vector<vector<int>>&dp){
        if(i<0){
            if(s==0)return 1;
            else {
                return 0;
            }
        }
        
        if(dp[i][s]!=-1)return dp[i][s];
        int pick = 0;
        if(s>=nums[i]){
            pick= f(i-1,s-nums[i],nums,dp);
        }
        int notpick=f(i-1,s,nums,dp);
        return dp[i][s]= pick+notpick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if((sum-target)<0 || (sum-target)%2!=0)return 0;
        int x= (sum-target)/2;
        int n= nums.size();
        vector<vector<int>>dp(n,vector<int>(x+1,-1));
        return f(n-1,(sum-target)/2,nums,dp);
    }
};