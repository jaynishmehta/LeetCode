class Solution {
    int f(int i,int t,vector<int>&coins,vector<vector<int>>&dp){
        if(i<0){
            if(t==0)return 1;
            else return 0;
        }
        
        if(dp[i][t]!=-1)return dp[i][t];
        int pick=0;
        if(t>=coins[i]){
           pick= f(i,t-coins[i],coins,dp);
        }
        int notpick= f(i-1,t,coins,dp);
        
        return dp[i][t]= pick+notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};