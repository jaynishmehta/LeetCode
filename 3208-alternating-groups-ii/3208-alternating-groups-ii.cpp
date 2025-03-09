class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& Co, int k) {
       long long int ans = 0;
        int i = 0;
        int j = 1;
        int n = Co.size();
        //2 pointer approach
        while (j < n + k && i < n) {
            int curr = j;
            int last = curr % n;

            while (Co[last] != Co[(last - 1 + n) % n] && curr < n + k - 1) {
                curr++;
                last = curr % n;
            }

            ans += max(curr - i - k + 1, 0);
            i = curr;
            j = i + 1;
        }

        return ans;
    }
};