class Solution {
    int f(int i,int j,vector<vector<int>>& tr,vector<vector<int>>& dp){
        int n= tr.size();
        if(i>=n || j> i)return 1e5;
        if(i==n-1)return tr[i][j];

        if(dp[i][j]!=-1)return dp[i][j];
        int down=0, adj=0;
        down = tr[i][j]+ f(i+1,j,tr,dp);
        adj = tr[i][j]+f(i+1,j+1,tr,dp);
        dp[i][j]= min(down,adj);
        return dp[i][j];

    }
public:
//tc- 0(n*n)
    int minimumTotal(vector<vector<int>>& tr) {
        vector<vector<int>>dp(tr.size(),vector<int>(tr.size()+1,0));
        // return f(0,0,tr,dp);
        int n = tr.size();
        dp[0][0]= tr[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i==0 && j==0)dp[0][0]= tr[0][0];
                else{
                    int down=1e4;
                    int adj = 1e4;
                    if(i>j){
                        down = tr[i][j]+dp[i-1][j];
                    }
                    if(j>0 && i>0) adj= tr[i][j]+dp[i-1][j-1];
                    dp[i][j]= min(down,adj);
                }
            }
        }
        // return dp[n-1][n-1]; // not correct
         // Return the minimum value in the last row
        return *min_element(dp[n - 1].begin(), dp[n - 1].begin() + n);

    }
};