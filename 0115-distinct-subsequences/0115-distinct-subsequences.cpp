class Solution {
    const int mod = 1e9 + 7;
   int bond(int i,int j,string &s, string &t,vector<vector<int>>&dp){
        if(j<0)return 1;
        if(i<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s[i]==t[j]){
            return dp[i][j]= ((bond(i-1,j-1,s,t,dp))%mod+ (bond(i-1,j,s,t,dp))%mod)%mod;  
                                            // this sinifiessearch for t[j] from the last of i in string s
        }
        else{   // if not found reduce the search space by 1 in s
            return dp[i][j]= (bond(i-1,j,s,t,dp))%mod;
        }
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m= t.size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        
        return bond(n-1,m-1,s,t,dp);
    }
};