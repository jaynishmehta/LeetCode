class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&v,vector<vector<char>>&grid){
        v[row][col]=1;
        vector<int>r={1,0,-1,0};
        vector<int>c={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow= row+r[i];
            int ncol= col+c[i];
            if((nrow>=0 && nrow<grid.size()) && (ncol>=0 && ncol<grid[0].size()) && (v[nrow][ncol]==0)&&(grid[nrow][ncol]=='1')){
                dfs(nrow,ncol,v,grid);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>v(grid.size(),vector<int>(grid[0].size(),0));
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && v[i][j]==0){
                    cnt++;
                    dfs(i,j,v,grid);
                    
                }
            }
        }
        return cnt;
    }
};