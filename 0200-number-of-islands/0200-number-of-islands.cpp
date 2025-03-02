class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&v,vector<vector<char>>&b){
        v[row][col]=1;
        vector<int>r1={1,0,-1,0};
        vector<int>r2={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow= row+r1[i];
            int ncol= col+r2[i];
            if((nrow>=0 && nrow<b.size()) && (ncol>=0 && ncol<b[0].size()) && !v[nrow][ncol] && b[nrow][ncol]=='1'){
                dfs(nrow,ncol,v,b);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        vector<vector<int>>v(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !v[i][j]){
                    dfs(i,j,v,grid);
                    cnt++;
                }
            }
        }
    
        return cnt;
    }
};