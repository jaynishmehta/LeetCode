class Solution {
    int MAX = 1e7+7;
    int f(int i, int sum, vector<int>& coins, vector<vector<long long int>>& dp) {
        // if (sum == 0) {
        //     return 0;
        // }
        if (i < 0) {
            if(sum==0)return 0;
            else{
            return MAX;
            }
        }
        
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }
        
        long long int notpick = f(i - 1, sum, coins, dp);
        
        long long int pick = MAX;
        if (coins[i] <= sum) {
            pick = 1+f(i, sum - coins[i], coins, dp);
        }
        
        dp[i][sum] = min(pick, notpick);
        return dp[i][sum];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long long int>> dp(n, vector< long long int>(amount + 1, -1));
        long long int result = f(n - 1, amount, coins, dp);
        return result == MAX ? -1 : result;
    }
};
