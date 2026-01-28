class Solution {
public:
    bool solve(string &s,int i,int j,vector<vector<int>>&dp){
        if(i>=j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]) return solve(s,i+1,j-1,dp);
        return 0;
    }
    string longestPalindrome(string s) {
        int n= s.size();
        vector<vector<int>>dp(s.size(),vector<int>(s.size()+1,-1));
        int maxlen=INT_MIN;
        int s_index=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp)==true){
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                        s_index=i;
                    }
                }
            }
        }
        return s.substr(s_index,maxlen);
    }
};