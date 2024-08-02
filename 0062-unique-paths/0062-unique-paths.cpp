class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n+1,0));
        dp[0][0]=1;   //bottom to top approach ,, base case 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)dp[0][0]=1;  // base case
                else{           //copy the memoization ref
                    int right=0,down=0; 
                    if(j>0){
                        right= dp[i][j-1];
                    }
                    if(i>0){
                        down = dp[i-1][j];
                    }
                    dp[i][j]= right+down;
                }
            }
        }
        return dp[m-1][n-1];
    }
};