class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // vector<vector<int>>ans;
        queue<pair<int,int>>q;
        vector<vector<int>> vis(image.size(),vector<int>(image[0].size(),0));
        vis[sr][sc]=1;
        q.push({sr,sc});
        int tochange= image[sr][sc];
        image[sr][sc]= color;
        while(!q.empty()){
            pair<int,int>p= q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            if((i+1>=0 && i+1<image.size())&&(j>=0 && j<image[0].size()) && vis[i+1][j]==0 && image[i+1][j]==tochange){
                vis[i+1][j]=1;
                q.push({i+1,j});
                image[i+1][j]=color;
            }
            if((i-1>=0 && i-1<image.size())&&(j>=0 && j<image[0].size()) && vis[i-1][j]==0 && image[i-1][j]==tochange){
                vis[i-1][j]=1;
                q.push({i-1,j});
                image[i-1][j]=color;
            }
            if((i>=0 && i<image.size())&&(j+1>=0 && j+1<image[0].size()) && vis[i][j+1]==0 && image[i][j+1]==tochange){
                vis[i][j+1]=1;
                q.push({i,j+1});
                image[i][j+1]=color;
            }
             if((i>=0 && i<image.size())&&(j-1>=0 && j-1<image[0].size()) && vis[i][j-1]==0 && image[i][j-1]==tochange){
                vis[i][j-1]=1;
                q.push({i,j-1});
                image[i][j-1]=color;
            }
        }
        return image;
    }
};