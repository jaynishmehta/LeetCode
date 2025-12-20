class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        if (hand.size() % gs != 0) return false;

        map<int, int> freq;
        for (int x : hand) freq[x]++;

        while (!freq.empty()) {
            int start = freq.begin()->first;
            int cnt = freq[start];

            for (int i = start; i < start + gs; i++) {
                if (freq[i] < cnt) return false;
                freq[i] -= cnt;
                if (freq[i] == 0) freq.erase(i);
            }
        }
        return true;
    }
};
