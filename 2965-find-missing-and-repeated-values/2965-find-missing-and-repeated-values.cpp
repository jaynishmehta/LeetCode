class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>v(grid.size()*grid.size()+1,0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                int x= grid[i][j];
                v[x]++;
            }
        }
        vector<int>ans(2,0);
        for(int i=1;i<v.size();i++){
            if(v[i]==2)ans[0]=i;
            if(v[i]==0)ans[1]=i;

        }
        return ans;
    }
};