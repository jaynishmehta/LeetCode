class Solution {
public:
    string answerString(string word, int n) {
        int m = word.size() - n + 1;
        if (n == 1) {
            return word;
        }

        string maxi = "";
        for (int i = 0; i < word.size(); ++i) {
            string sub = word.substr(i, m);  // C++ will safely handle overlength substrings
            if (sub > maxi) {
                maxi = sub;
            }
        }
        return maxi;
    }
};
