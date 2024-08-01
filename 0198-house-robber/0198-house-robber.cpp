class Solution {
//     int solve(vector<int>& nums,vector<int>&dp,int i){
//         if(i<0)return 0;
        
//         if(dp[i]!=-1)return dp[i];
        
//         int take= nums[i]+solve(nums,dp,i-2);
//         int nottake= 0+solve(nums,dp,i-1);
//         return dp[i]=max(take,nottake);
//     }
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(nums.size()+1,0);
        dp[0]=0;
        dp[1]=nums[0];
        
        for(int i=2;i<=n;i++){
            int take= nums[i-1]+dp[i-2];
            int nottake= 0+dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[n];
    }
};