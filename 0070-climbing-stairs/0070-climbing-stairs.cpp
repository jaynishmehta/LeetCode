class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1; // Base case: 1 way to climb 0 or 1 step
        // inintialize the array do not give -1 just the size;
        vector<int> dp(n + 1); // Initialize the dp array
        dp[0] = 1; // 1 way to stay at the ground (doing nothing)
        dp[1] = 1; // 1 way to reach the first step

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2]; // Ways to reach the ith step
        }

        return dp[n]; 
    }
};
