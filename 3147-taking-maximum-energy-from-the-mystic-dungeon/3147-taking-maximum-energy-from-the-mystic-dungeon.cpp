
class Solution {
public:
    vector<int> Dp;

    int providers(vector<int>& energys, int k, int i) {
        if (i >= energys.size()) return 0;
        if (Dp[i] != INT_MIN) return Dp[i];
        return Dp[i] = energys[i] + providers(energys, k, i + k);
    }

    int  maximumEnergy(vector<int>& energys, int k) {
        Dp.assign(energys.size(), INT_MIN); // Efficient initialization
        int f_ans = INT_MIN;
        for (int i = 0; i < energys.size(); i++) {
            f_ans = max(f_ans, providers(energys, k, i));
        }
        return f_ans;
    }
};