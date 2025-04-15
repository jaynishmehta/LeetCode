
class Solution {
    // declaring outside handles the tle.
     int dp[100][100];
 int f(int i,int j,vector<vector<int>>& mt){
        int m= mt.size();
        int n = mt[0].size();
        
        if(i>=m ||j<0 || j>=n)return 100000;
        if(i==m-1)return mt[i][j];

        if(dp[i][j]!=-100000)return dp[i][j];

        // int below=1e5,left=1e5,right=1e5;

        int below = mt[i][j]+f(i+1,j,mt);
        int left = mt[i][j]+f(i+1,j-1,mt);
        int right = mt[i][j]+f(i+1,j+1,mt);

        int temp = min(below,min(left,right));
        return dp[i][j]=temp;
    }
public:
    int minFallingPathSum(vector<vector<int>>& mt) {
       
        int minii=1e5;
        for(int i=0; i<100; ++i){
            for(int j=0; j<100; ++j){
                dp[i][j] = -100000;
            }
        }
        for(int i=0;i<mt[0].size();i++){
            
            minii = min(f(0,i,mt),minii);
        }
        return minii;
    }
};