class Solution {
public:
    int cnts(string &s){
        int n1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')n1++;
        }
        return n1; // n2= s.size()-n1;
    }
    int solve(int i,int used0,int used1,vector<string>& strs,int m,int n,vector<vector<vector<int>>>&dp){
       
        if(used0>m || used1>n){
            return -1e9;
        }

        if(i==strs.size())return 0;

        if(dp[i][used0][used1]!=-1)return dp[i][used0][used1];
        
        int z1=cnts(strs[i]);
        int z0= strs[i].size()-z1;
        int take= 1+ solve(i+1,used0+z0,used1+z1,strs,m,n,dp);
        int nottake= 0+ solve(i+1,used0,used1,strs,m,n,dp);

        return dp[i][used0][used1]= max(take,nottake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(601,vector<vector<int>>(101,vector<int>(101,-1)));
        return solve(0,0,0,strs,m,n,dp);
    }
};