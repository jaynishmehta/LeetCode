//this question can be solve using  as number of subsets(s1,s2) whose abs(diff) is equal to target (dp-18 striver)
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
        vector<vector<int>>dp(n,vector<int>(x+1,0));
        // return f(n-1,(sum-target)/2,nums,dp);  // memoization (dp-18_lec) s1+s2=s, s1-s2=target; s2= (s-target)/2  ,, find number of such s2 subsequence exist;
       
        dp[0][0] = 1;  // there's one way to get sum 0 with no elements
        if (nums[0] <= x) dp[0][nums[0]] += 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= x; j++) {
                int notPick = dp[i - 1][j];
                int pick = (j >= nums[i]) ? dp[i - 1][j - nums[i]] : 0;
                dp[i][j] = pick + notPick;
             }
        }
    
    return dp[n - 1][x];
    }
};