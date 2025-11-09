class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }

        long long ans = LLONG_MAX;

        for (auto& it : m) {
            auto& v = it.second;
            if (v.size() < 3) continue;

            // indices already in increasing order
            for (int i = 0; i + 2 < v.size(); i++) {
                long long d1 = abs(v[i] - v[i + 1]);
                long long d2 = abs(v[i + 1] - v[i + 2]);
                long long d3 = abs(v[i] - v[i + 2]);
                long long total = d1 + d2 + d3;  // "triangle" perimeter of indices
                ans = min(ans, total);
            }
        }

        return (ans == LLONG_MAX) ? -1 : (int)ans;
    }
};
