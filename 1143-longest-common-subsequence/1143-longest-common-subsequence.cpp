class Solution {
    int bond(int i,int j,string &t1,string &t2,vector<vector<int>>&dp){
        if(i<0 || j<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        
        if(t1[i]==t2[j]){
            return dp[i][j]= 1 + bond(i-1,j-1,t1,t2,dp);
        }
        else{
            return dp[i][j]=max(bond(i-1,j,t1,t2,dp),bond(i,j-1,t1,t2,dp));
        }
    }
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n= t1.size();
        int m= t2.size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return bond(n-1,m-1,t1,t2,dp);
    }
};