class Solution {
public:
    bool isCircularSentence(string s) {
        vector<char>v;
        if(s[0]!=s[s.size()-1])return false;
         for (int i = 1; i < s.size() - 1; i++) {
            // Check if current character is a space (end of a word)
            if (s[i] == ' ') {
                
                if (s[i - 1] != s[i + 1]) return false;
            }
        }
        
        return true; 
    } 
};