class Solution {
public:
    int canBeTypedWords(string text, string bl) {
        set<char> broken(bl.begin(), bl.end());
        int count = 0;
        bool bad = false;

        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                if (!bad) count++;
                bad = false;
            } else {
                if (broken.count(text[i])) bad = true;
            }
        }

        return count;
    }
};
