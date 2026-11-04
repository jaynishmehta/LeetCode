class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,0);
        int n= nums.size();
        dp[0]=0,dp[1]=nums[0];
        for(int i=2;i<=nums.size();i++){
            int rob= nums[i-1]+dp[i-2];
            int not_rob= dp[i-1];
            dp[i]= max(rob,not_rob);
        }
        
        return dp[n];

    }
};