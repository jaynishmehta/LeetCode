class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&v,vector<vector<char>>&b){
        v[row][col]=1;
        vector<int>r1={1,0,-1,0};
        vector<int>r2={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow= row+r1[i];
            int ncol= col+r2[i];
            if((nrow>=0 && nrow<b.size()) && (ncol>=0 && ncol<b[0].size()) && !v[nrow][ncol] && b[nrow][ncol]=='O'){
                // v[nrow][ncol]=1;
                dfs(nrow,ncol,v,b);
            }
        }

    }
    void solve(vector<vector<char>>& b) {
        queue<pair<int,int>>q;
        for(int i =0;i<b.size();i++){
            if(b[i][0]=='O')q.push({i,0});
            if(b[i][b[0].size()-1]=='O')q.push({i,b[0].size()-1});
         }
         for(int i=0;i<b[0].size();i++){
            if(b[0][i]=='O')q.push({0,i});
            if(b[b.size()-1][i]=='O')q.push({b.size()-1,i});
         }
         vector<vector<int>>v(b.size(),vector<int>(b[0].size(),0));
         while(!q.empty()){
            int row=q.front().first;
            int col = q.front().second;
            q.pop();
            dfs(row,col,v,b);
         }
         for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                if(b[i][j]=='O' && v[i][j]==0)b[i][j]='X';
            }
         }

    }
};