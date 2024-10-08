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
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=m;i++)dp[0][i]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1]==t2[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        // return bond(n-1,m-1,t1,t2,dp);
        return dp[n][m];
    }
};