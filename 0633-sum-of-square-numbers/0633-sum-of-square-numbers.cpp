class Solution {
public:
    bool judgeSquareSum(int c) {
        int l= 0;
        // int r=c;
         long long r = static_cast<long long>(sqrt(c));
        while (l <= r) {
            long long sum = l * l + r * r;
            if (sum == c) {
                return true;
            } else if (sum < c) {
                ++l;
            } else {
                --r;
            }
        }
        return false;
    }
};