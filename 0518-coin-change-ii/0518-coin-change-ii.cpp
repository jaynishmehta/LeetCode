class Solution {
public:
    int f(int i,int amount,vector<vector<int>>& dp,vector<int>& coins){
        if(i==coins.size()){
            return amount==0;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int pick =0;
        int notpick = f(i+1,amount,dp,coins);
        if(amount>=coins[i]){
            pick = f(i,amount-coins[i],dp,coins);
        }
        return dp[i][amount]= pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
        // return f(0,amount,dp,coins);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)dp[0][i]=1;
        }
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                long long int notpick= dp[i-1][j];
                long long int pick=0;
                if(coins[i]<=j){
                    pick= dp[i][j-coins[i]];
                }
                dp[i][j]= pick+notpick;
            }
        }
        return dp[coins.size()-1][amount];
    }
};