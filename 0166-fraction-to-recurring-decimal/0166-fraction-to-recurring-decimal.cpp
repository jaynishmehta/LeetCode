class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if (num == 0) return "0";

        string ans;

        // Handle sign
        if ((num < 0) ^ (den < 0)) ans += "-";

        long long numerator = llabs((long long)num);
        long long denominator = llabs((long long)den);

        // Integer part
        ans += to_string(numerator / denominator);
        long long rem = numerator % denominator;
        if (rem == 0) return ans;

        ans += ".";

        // Map remainder -> index in answer string
        unordered_map<long long, int> seen;

        while (rem != 0) {
            if (seen.count(rem)) {
                ans.insert(seen[rem], "(");
                ans += ")";
                return ans;
            }

            seen[rem] = ans.size();

            rem *= 10;
            ans += to_string(rem / denominator);
            rem %= denominator;
        }

        return ans;
    }
};
