class Solution {
    long long int MAX= 1e7+7;
    int solve(int i,int sum,vector<vector<long long int>>&dp,vector<int>& coins,int amount){
        if(sum==amount)return 0;
        if(i < 0 || sum > amount){
             return MAX;
        }
        
        if(dp[i][sum]!=-1)return dp[i][sum];
        
        long long int take=MAX;
        if(sum+coins[i]<=amount){
            take=1+ solve(i,sum+coins[i],dp,coins,amount);
        }
        long long int nottake= solve(i-1,sum,dp,coins,amount);
        
        return dp[i][sum]= min(take,nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<long long int>>dp(n,vector< long long int>(amount+1,-1));
        long long result= solve(n-1,0,dp,coins,amount);
        return result == MAX ? -1 : result;
    }
};