class Solution {
public:
    int solve(int i,string s,vector<int>&dp){
        if(i==s.size())return 1;

        if(s[i]=='0')return 0;
        if(dp[i]!=-1)return dp[i];

        int take1 = solve(i+1,s,dp);
        int take2= 0;

        if(i+1<s.size() && (s[i]=='1' || s[i]=='2' && s[i+1]-'0'<7)){
            take2= solve(i+2,s,dp);
        }
        return dp[i]=take1+take2;
        
    }
    int numDecodings(string s) {
        vector<int>dp(101,-1);
        return solve(0,s,dp);
    }
};