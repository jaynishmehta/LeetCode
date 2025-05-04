class Solution {
public:
    bool f(int i, int lastJump, vector<int>& stones, vector<vector<int>>& dp, unordered_map<int, int>& stoneIndex) {
        int n = stones.size();
        if (i == n - 1) return true;
        if (dp[i][lastJump] != -1) return dp[i][lastJump];

        for (int jump = lastJump - 1; jump <= lastJump + 1; ++jump) {
            if (jump > 0) {
                int nextPos = stones[i] + jump;
                if (stoneIndex.count(nextPos)) {
                    int nextIdx = stoneIndex[nextPos];
                    if (f(nextIdx, jump, stones, dp, stoneIndex)) {
                        return dp[i][lastJump] = true;
                    }
                }
            }
        }

        return dp[i][lastJump] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, int> stoneIndex;
        for (int i = 0; i < n; ++i) {
            stoneIndex[stones[i]] = i;
        }

        // Max possible jump is <= n (since jumps start at 1 and can't exceed n-1 steps)
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return f(0, 0, stones, dp, stoneIndex);
    }
};
