class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans(n);
        // ans.push_back({1});
        ans[0]={1};
        for(int i=1;i<n;i++){
            int j=0;
            for (int j = 0; j <= i; j++) {
                if(j==0 || j==i){
                    ans[i].push_back(1);
                }
                else{
                    ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
                
            }
        }
        
        return ans;
    }
};