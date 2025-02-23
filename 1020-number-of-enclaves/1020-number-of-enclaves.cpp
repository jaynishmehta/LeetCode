class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& v,vector<vector<int>>& grid){
        v[i][j]=1;
        vector<int>x1={1,0,-1,0};
        vector<int>x2={0,1,0,-1};
        for(int k=0;k<4;k++){
            int ni= i+x1[k];
            int nj= j+x2[k];
            if((ni>=0 && ni<grid.size())&&(nj>=0 && nj<grid[0].size()) && !v[ni][nj] && grid[ni][nj]==1){
                dfs(ni,nj,v,grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>>v(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>>q;
        int ans=0;
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==1)q.push({i,0});
            if(grid[i][grid[0].size()-1]==1)q.push({i,grid[0].size()-1});
        }
        for(int i=0;i<grid[0].size();i++){
            if(grid[0][i]==1)q.push({0,i});
            if(grid[grid.size()-1][i]==1)q.push({grid.size()-1,i});
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            dfs(i,j,v,grid);
        }
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && v[i][j]==0)cnt++;
            }
        }
        return cnt;

    }
};