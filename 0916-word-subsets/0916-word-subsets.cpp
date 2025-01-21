class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        vector<string> ans;
        vector<int> maxFreq(26, 0);  // Max frequency of each letter across all words in w2

        // Step 1: Calculate maximum frequency for each letter in w2
        for (string &word : w2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        // Step 2: Check each word in w1
        for (string &word : w1) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            bool valid = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
