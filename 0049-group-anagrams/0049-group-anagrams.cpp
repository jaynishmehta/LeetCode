class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagramGroups;
        
        for (const string& s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            
            anagramGroups[sortedStr].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto it  : anagramGroups) {
            result.push_back(it.second);
        }
        return result;
        
    }
};