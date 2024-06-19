class Solution {
    bool f(int i,vector<int>&nums,int s, int currsum, vector<vector<int>>&dp){
        
        if(i==nums.size()){
            return currsum==s;
        }
        
        if(dp[i][currsum]!=-1)return dp[i][currsum];
        
        bool pick=false;
        if(currsum+nums[i]<=s){
            pick= f(i+1,nums,s,currsum+nums[i],dp);
        }
        bool notpick= f(i+1,nums,s,currsum,dp);
        dp[i][currsum]= pick||notpick;
        return dp[i][currsum];
        
    }
public:
    bool canPartition(vector<int>& nums) {
       int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2!=0)return false;
        int n= nums.size();
        int k= sum/2;
        vector<vector<int>>dp(n,vector<int>(k + 1,-1));
        return f(0,nums,sum/2,0,dp);
    }
};