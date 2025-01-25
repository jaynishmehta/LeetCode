class Solution {
    int solve(int i,vector<int>&dp,vector<int>&nums,int n){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        
        int rob= nums[i]+solve(i+2,dp,nums,n);
        
        int not_rob= 0+solve(i+1,dp,nums,n);
        
        return dp[i]= max(rob,not_rob);
    }
public:
    int rob(vector<int>& nums) {
        // vector<int>dp1(nums.size(),-1);
        // vector<int>dp2(nums.size(),-1);
        int n = nums.size();
        if(n==1)return nums[0];
        // int m1= solve(0,dp1,nums,n-1);
        // int m2= solve(1,dp2,nums,n);
        // return max(m1,m2);
        vector<int>dp1(n+1,0);
        vector<int>dp2(n+1,0);
        dp1[0]=0;
        dp1[1]=nums[0];
        for(int i=2;i<=n-1;i++){
            int rob= nums[i-1]+dp1[i-2];
            int not_rob= 0+dp1[i-1];
            dp1[i]= max(rob,not_rob);
        }
        int m1= dp1[n-1];
        dp2[0]=0;
        dp2[2]=nums[1];
        for(int i=3;i<=n;i++){
            int rob= nums[i-1]+dp2[i-2];
            int not_rob= 0+dp2[i-1];
            dp2[i]= max(rob,not_rob);
        }
        int m2= dp2[n];
        return max(m1,m2);
    }
};