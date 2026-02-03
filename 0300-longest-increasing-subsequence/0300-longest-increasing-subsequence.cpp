class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        int n=nums.size();
        int lis=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(nums[j]<nums[i]){
                    dp[i]= max(dp[i],1+dp[j]);
                    lis= max(lis,dp[i]);
                }
            }
        }
        return lis;

    }
};

// class Solution {
// public:
//     int solve(int i, vector<int>& nums, vector<vector<int>>& dp, int prev_index) {
//         if (i >= nums.size()) return 0;
//         if (dp[i][prev_index + 1] != -1) return dp[i][prev_index + 1];

//         int pick = 0;
//         if (prev_index == -1 || nums[i] > nums[prev_index]) {
//             pick = 1 + solve(i + 1, nums, dp, i);
//         }
//         int not_pick = solve(i + 1, nums, dp, prev_index);

//         return dp[i][prev_index + 1] = max(pick, not_pick);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//         return solve(0, nums, dp, -1);
//     }
// };
