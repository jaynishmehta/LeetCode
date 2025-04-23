class Solution {
    int f(int i,int j,string &t1,string &t2,vector<vector<int>>&dp){
        if(i==t1.size() || j==t2.size()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int take= 0,nottake=0,maxi=0;
        if(t1[i]==t2[j]){
            take = 1+ f(i+1,j+1,t1,t2,dp);
        }
        else nottake = max(f(i+1,j,t1,t2,dp),f(i,j+1,t1,t2,dp));
        return dp[i][j]= max(take,nottake);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        // return f(0,0,text1,text2,dp);
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                int take=0,nottake=0;
                if(text1[i-1]==text2[j-1]){
                    take = 1+ dp[i-1][j-1];
                }
                else{
                    nottake= max(dp[i-1][j],dp[i][j-1]);
                }
                dp[i][j]= max(take,nottake);
            }
        }
        return dp[text1.size()][text2.size()];
    }
}; 