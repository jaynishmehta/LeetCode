class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
     vector<vector<int>>v(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    v[i][j]=1;
                    q.push({{i,j},0});   // pushing all the zeroes cordinate and distance=0 inititally;
                }
            }
        }
        vector<int>d1={1,0,-1,0}; //for traversing in four direction 
        vector<int>d2={0,1,0,-1};
        while(!q.empty()){
            int row= q.front().first.first;
            int col= q.front().first.second;
            int d= q.front().second;
            ans[row][col]=d;   //marking the distance as an ans in ansvector
            q.pop();
            for(int i=0;i<4;i++){
                int nrow= row+d1[i];
                int ncol = col+d2[i];
                if((nrow>=0 && nrow<mat.size()) && (ncol>=0 && ncol<mat[0].size()) && !v[nrow][ncol]){ //checking if inside the mat and not visited
                     q.push({{nrow,ncol},d+1});
                    v[nrow][ncol]=1;
                }
            }
        }
        return ans;
    }    
    
};