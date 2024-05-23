// class Solution {
// public:
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>>res;
//         vector<string>path;
//         func(0,s,path,res);
//         return res;
//     }
//     void func(int index,string s,vector<string>&path,vector<vector<string>>&res){
//         if(index==s.size()){
//             res.push_back(path);
//             return;
//         }
//         for(int i=index;i<s.size();++i){
//             if(ispalindrome(s,index,i)){
//                 path.push_back(s.substr(index,i-index+1));
//                 func(i+1,s,path,res);
//                 path.pop_back();
//             }
//         }
//     }
//     bool ispalindrome(string s,int start,int end){
//         while(start<=end){
//             if(s[start++]!=s[end]){
//                 return false;
//             }
//         }
//         return true;
//     }
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        // If we've reached the end of the string, add the current partition to the result list
        if (start == s.length()) {
            result.push_back(path);
            return;
        }
        // Explore all possible partitions
        for (int end = start + 1; end <= s.length(); ++end) {
            // If the current substring is a palindrome, add it to the current path
            if (isPalindrome(s, start, end - 1)) {
                path.push_back(s.substr(start, end - start));
                // Recur to find other partitions
                backtrack(s, end, path, result);
                // Backtrack to explore other partitions
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        // Check if the substring s[left:right+1] is a palindrome
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};

// };