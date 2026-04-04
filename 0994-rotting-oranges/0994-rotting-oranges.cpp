class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>v(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    v[i][j]=1;
                }
            }
        }
        int maxtime=0;
        while(!q.empty()){
            pair<int,pair<int,int>>x = q.front();
            q.pop();
            int time= x.first;
            maxtime=max(maxtime,time);
            int row= x.second.first;
            int col= x.second.second;
            vector<int>r={1,0,-1,0};
            vector<int>c={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int nrow= row+r[i];
                int ncol= col+c[i];
                if((nrow>=0 && nrow<grid.size())&&(ncol>=0 && ncol<grid[0].size())&&(v[nrow][ncol]==0) && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    v[nrow][ncol]=1;
                    q.push({time+1,{nrow,ncol}});
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return maxtime;
    }
};