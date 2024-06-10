class Solution {
    int f(int i,int maxi,vector<int>& rewardValues,vector<vector<int>> &dp){
        if(i==rewardValues.size())return maxi;
        if(maxi>rewardValues.back())return maxi;
        
        if(dp[i][maxi]!=-1)return dp[i][maxi]; //dp step3
        int take= (maxi<rewardValues[i])?f(i+1,maxi+rewardValues[i],rewardValues,dp):maxi;
        int nottake=f(i+1,maxi,rewardValues,dp);
        return dp[i][maxi] = max(take,nottake); //dp step 2
    }
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        int maxi=0;
        vector<vector<int>> dp(2001, vector<int>(2001, -1)); //dp step-1
        return f(0,maxi,rewardValues,dp);
    }
};