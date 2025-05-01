class Solution {
    bool checkallstar(string &p,int j){
        while(j>=0){
            if(p[j]!='*')return false;
            j--;
        }
        return true;
    }

    int f(string & s,string & p ,int i,int j,vector<vector<int>>& dp){
        if(i<0 && j<0)return 1;
        if(i>=0 && j<0)return 0;
        if(i<0 && j>=0){
           return  checkallstar(p,j);
        }
        if(dp[i][j]!=-1)return dp[i][j];

        if((s[i]==p[j]) || (p[j]=='?')){
            return dp[i][j]= f(s,p,i-1,j-1,dp);
        }
        else{
            if(p[j]=='*'){
                return dp[i][j]= (f(s,p,i-1,j,dp)||f(s,p,i,j-1,dp));
            }
            else{
                return 0;
            }
        }

    }
public:
    // starts from back;
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        // Create a DP table to memoize results
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(s,p,n-1,m-1,dp);
    }
};