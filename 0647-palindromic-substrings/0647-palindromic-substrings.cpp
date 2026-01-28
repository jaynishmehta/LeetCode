// class Solution {
// public:
//     bool solve(string &s,int i,int j,vector<vector<int>>&dp){
//         if(i>=j){
//             return 1;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         if(s[i]==s[j]) return solve(s,i+1,j-1,dp);
//         return 0;
//     }
//     string longestPalindrome(string s) {
//         int n= s.size();
//         vector<vector<int>>dp(s.size(),vector<int>(s.size()+1,-1));
//         int maxlen=INT_MIN;
//         int s_index=0;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 if(solve(s,i,j,dp)==true){
//                     if(j-i+1>maxlen){
//                         maxlen=j-i+1;
//                         s_index=i;
//                     }
//                 }
//             }
//         }
//         return s.substr(s_index,maxlen);
//     }
// };
class Solution {
public:
    int is_palin(int i,int j,string s,vector<vector<int>>&dp){
        if(i>=j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])return is_palin(i+1,j-1,s,dp);
        return 0;
    }
    int countSubstrings(string s) {
        int n= s.size();
        vector<vector<int>>dp(s.size(),vector<int>(s.size()+1,-1));
        int maxlen=INT_MIN;
        int s_index=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(is_palin(i,j,s,dp)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};