class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row=grid.size();
        int col= grid[0].size();
        int row_max=-1,col_max=-1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    row=min(row,i);
                    row_max= max(row_max,i);
                    col= min(col,j);
                    col_max= max(col_max,j);
                }
            }
        }
        return (row_max-row+1)*(col_max-col+1);
    }
};