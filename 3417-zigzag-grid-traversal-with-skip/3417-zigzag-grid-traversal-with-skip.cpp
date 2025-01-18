class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int>ans;
        int temp=1;
        for(int i=0;i<grid.size();i++){
            if(temp==1){
                for(int j=0;j<grid[0].size();j+=2){
                    ans.push_back(grid[i][j]);
                }
                temp*=-1;
            }
            else if(temp==-1 && (grid[0].size()%2==0)){
                for(int j=grid[0].size()-1;j>=0;j-=2){
                    ans.push_back(grid[i][j]);
                }
                temp*=-1;
            }
            else if(temp==-1 && (grid[0].size()%2==1)){
                for(int j= grid[0].size()-2;j>=0;j-=2){
                    ans.push_back(grid[i][j]);
                }
                temp*=-1;
            }
            
        }
        return ans;
    }
};