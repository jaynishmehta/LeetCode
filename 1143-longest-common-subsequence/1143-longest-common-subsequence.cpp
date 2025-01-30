class Solution {
public:
    int solve(int i,int j,string &t1,string &t2,vector<vector<int>>&dp){
        if(i>=t1.size() || j>= t2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int pick=0,not_pick=0;
        if(t1[i]==t2[j]){
            pick= 1+ solve(i+1,j+1,t1,t2,dp);
        }
        else{
            not_pick= max(solve(i+1,j,t1,t2,dp),solve(i,j+1,t1,t2,dp));
        }
        return dp[i][j]=pick+not_pick;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        // return solve(0,0,text1,text2,dp);
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]= 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};