
class Solution {
    const int mod = 1e9 + 7;
    int solve(int i,int j,string &s,string & t,vector<vector<int>>&dp){
        if(j==t.size())return 1;
        if(i==s.size())return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        
        long long take=0;
        if(s[i]==t[j]){
            take= solve(i+1,j+1,s,t,dp)%mod;
        }
        long long int nottake= solve(i+1,j,s,t,dp)%mod;
        return dp[i][j]=(take%mod+nottake%mod)%mod;
    }
public:

    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        return solve(0,0,s,t,dp)%mod;
    }
};