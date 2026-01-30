// class Solution {
//     int solve(int i,int n,vector<int>&dp,vector<int>&nums,int maxi){
//         if(i==n){
//             return 1;
//             }
//         if(dp[i]!=-1)return dp[i];
//         int take= nums[i]*solve(i+1,n,dp,nums,maxi);
//         // int not_take= 0;
        
//         maxi= max(take,maxi);
//         return dp[i]=maxi;
//     }
// public:
//     int maxProduct(vector<int>& nums) {
//         vector<int>dp(nums.size(),-1);
//         int n= nums.size();
//         int maxi=0;
//         return solve(0,n,dp,nums,maxi);
//     }
// };
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prod=1;

        for(int i=0;i<nums.size();i++)
        {
          prod*=nums[i];
          maxi=max(prod,maxi);
          if(prod==0)
           prod=1;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
          prod*=nums[i];

          maxi=max(prod,maxi);
          if(prod==0)
           prod=1;
        }
        return maxi;
    }
};