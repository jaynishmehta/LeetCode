class Solution {
public:
    //4d dp pb;
    vector<pair<int,int>> d = {{-1,1},{1,1},{1,-1},{-1,-1}};

    int solve(int prev,int r,int c,vector<vector<int>>&grid,pair<int,int>&dir,bool dir_change,vector<vector<vector<vector<int>>>>& dp,int dir_idx){
        if(r>=grid.size() || r<0 || c>=grid[0].size() || c<0){
            return 0;
        }
        if (dp[r][c][dir_idx][dir_change] != -1)return dp[r][c][dir_idx][dir_change];
        
        int nx= r+dir.first , ny = c+dir.second;
        int notturn=0,turn=0;
        //moving in same drn
        if((nx<grid.size() && nx>=0 && ny<grid[0].size() && ny>=0)&& (grid[nx][ny]!=prev &&grid[nx][ny]!=1)){
            notturn= 1+ solve(grid[nx][ny],nx,ny,grid,dir,dir_change,dp,dir_idx);

        }
        //when dir changes
        int new_dir_idx = (dir_idx + 1) % 4; //rotates in clockwise
        int nx1= r + d[new_dir_idx].first, ny1 = c + d[new_dir_idx].second; // pos of new cordinates in chnagese drn
        if((nx1<grid.size() && nx1>=0 && ny1<grid[0].size() && ny1>=0)&& (grid[nx1][ny1]!=prev &&grid[nx1][ny1]!=1) && dir_change==false){
            // dir={m[dir].first,m[dir].second};
            pair<int,int> new_dir = d[new_dir_idx];
            turn = 1+ solve(grid[nx1][ny1],nx1,ny1,grid,new_dir,true,dp,new_dir_idx);
        }
        return dp[r][c][dir_idx][dir_change]= max(turn,notturn);

    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        // vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size()+1,-1));
        int n = grid.size(), mcol = grid[0].size();
        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(mcol, vector<vector<int>>(4, vector<int>(2, -1)))
        );
        int maxi= 1;
        bool check_one=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){

                if(grid[i][j]==1){
                    check_one=true;

                    for(int k=0;k<4;k++){  // moved in all 4 diagonal drn
                        int nx= i+d[k].first, ny= j+d[k].second;  
                        if((nx>=grid.size() || nx<0 || ny>=grid[0].size() || ny<0)|| grid[nx][ny]!=2)continue;
                        pair<int,int>p={d[k].first,d[k].second};
                        maxi = max(maxi, 2+solve(2,nx,ny,grid,p,false,dp,k));
                    }

                }
            }
        }
        if(check_one==false)return 0;
        return maxi;
    }
};