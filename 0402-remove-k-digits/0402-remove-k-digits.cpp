class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        int digitsToRemove = k;
        int i = 0;
        
        while (digitsToRemove > 0 && i < num.size()) {
            if (i == 0 || num[i] >= num[i - 1]) {
                i++;
            } else {
                num.erase(i - 1, 1);
                digitsToRemove--;
                i = max(0, i - 1);
            }
        }
        
        // If there are still digits to be removed, remove them from the end
        while (digitsToRemove > 0 && !num.empty()) {
            num.pop_back();
            digitsToRemove--;
        }
        
        // Remove leading zeros
        int leadingZeros = 0;
        while (leadingZeros < num.size() && num[leadingZeros] == '0') {
            leadingZeros++;
        }
        num = (leadingZeros == num.size()) ? "0" : num.substr(leadingZeros);
        
        return num.empty() ? "0" : num;
    }
};

