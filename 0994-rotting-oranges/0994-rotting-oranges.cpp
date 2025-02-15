class Solution {
public:
    // int bfs()
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt=0;
        queue<pair<int,pair<int,int>>>q;  //(time,{i,j});
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            
            // pair<int,int>p=q.front();
            pair<int,pair<int,int>>p= q.front();
            q.pop();
            int i= p.second.first;
            int j= p.second.second;
            int t = p.first;
            if(((i+1>=0 && i+1<grid.size()) &&(j>=0 && j<grid[0].size())) && vis[i+1][j]==0 && grid[i+1][j]==1){
                grid[i+1][j]=2;
                vis[i+1][j]=1;
                q.push({t+1,{i+1,j}});
                cnt=max(cnt,t);
            }
            if(((i-1>=0 && i-1<grid.size()) &&(j>=0 && j<grid[0].size())) && vis[i-1][j]==0 && grid[i-1][j]==1){
                grid[i-1][j]=2;
                vis[i-1][j]=1;
                q.push({t+1,{i-1,j}});
                cnt=max(cnt,t);
            }
            if(((i>=0 && i<grid.size()) &&(j+1>=0 && j+1<grid[0].size())) && vis[i][j+1]==0 && grid[i][j+1]==1){
                grid[i][j+1]=2;
                vis[i][j+1]=1;
                q.push({t+1,{i,j+1}});
                cnt=max(cnt,t);
            }
            if(((i>=0 && i<grid.size()) &&(j-1>=0 && j-1<grid[0].size())) && vis[i][j-1]==0 && grid[i][j-1]==1){
                grid[i][j-1]=2;
                vis[i][j-1]=1;
                q.push({t+1,{i,j-1}});
                cnt=max(cnt,t);
            }
            cnt= max(cnt,t);
        }

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return cnt;

    }
};