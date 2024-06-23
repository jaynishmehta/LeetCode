class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        vector<long long int>dp(n+1,0);
        dp[1]=nums[0];
        for(int i=1;i<nums.size();i++){
            long long int pick1= dp[i]+nums[i];
            long long int pick2=dp[i-1]+nums[i-1]+ -1*nums[i];
            dp[i+1]=max(pick1,pick2);
        }
        return dp[n];
    }
};

// class Solution {
//     int f(int i,int n,vector<int>&nums){
//         if(i>n){
//             return 0;
//         }
        
//         int pickone= nums[i]+f(i+1,n,nums);
//         int picktwo= 0;
//         if(i>0){
//             picktwo= f(i-1,n,nums)+nums[i-1]-1*nums[i]+f(i+1,n,nums);
//         }
//         return max(pickone,picktwo);
//     }
// public:
//     long long maximumTotalCost(vector<int>& nums) {
//         int n = nums.size();
//         return f(0,n-1,nums);
//     }
// };