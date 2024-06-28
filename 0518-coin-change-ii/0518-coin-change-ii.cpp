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
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // return f(n-1,amount,coins,dp);
        for (int i = 0; i <= amount; i++) {
        if (i % coins[0] == 0)
            dp[0][i] = 1; 
            // At ind==0, we are considering the first element, if the target value is                                   divisible by the first coin’s value, we set the cell's value as 1 or else 0.
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int pick=0;
                if(j>=coins[i]){
                   pick= dp[i][j-coins[i]];
                }
                int notpick= dp[i-1][j];
                dp[i][j]=pick+notpick;
            }
        }
        return dp[n-1][amount];
    }
};