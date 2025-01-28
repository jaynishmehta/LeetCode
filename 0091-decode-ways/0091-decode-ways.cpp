class Solution {
public:
    int solve(int i,string s,vector<int>&dp,int n){
        if(i==n)return 1;
        if((s[i]-'0')==0){
            // i++;
            return 0;
        }
        // if(i>n)return 0;
        
        if(dp[i]!=-1)return dp[i];
        int take1= solve(i+1,s,dp,n);
        int take2=0;
        if(i+1<n && (s[i]=='1' || (s[i]=='2' && s[i+1]-'0'<=6))){
            take2=solve(i+2,s,dp,n);
        }
        // maxi= max(take1+take2,maxi);
        return dp[i]=take1+take2;

    }

    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        int n= s.size();
        return solve(0,s,dp,n);
    }
};