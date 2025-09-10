class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& lang, vector<vector<int>>& frnd) {
        vector<int> unhappy;
        unordered_map<int,int> m;
        set<int> s1;

        for (int i = 0; i < frnd.size(); i++) {
            set<int> s;
            int f1 = frnd[i][0] - 1, f2 = frnd[i][1] - 1;

            // put both friends' languages in a set
            for (int l : lang[f1]) s.insert(l);
            for (int l : lang[f2]) s.insert(l);

            // if no common language (disjoint sets)
            if (s.size() == lang[f1].size() + lang[f2].size()) {
                unhappy.push_back(f1);
                unhappy.push_back(f2);
                s1.insert(f1);
                s1.insert(f2);
            }
        }

        // count language frequencies ONLY for unhappy users
        for (int u : s1) {
            for (int l : lang[u]) {
                m[l]++;
            }
        }

        int maxFreq = 0;
        for (auto &it : m) {
            maxFreq = max(maxFreq, it.second);
        }

        return (int)s1.size() - maxFreq;
    }
};
