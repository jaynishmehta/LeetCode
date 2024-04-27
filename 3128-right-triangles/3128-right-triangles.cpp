class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        vector<int> rows(grid.size(), 0);
        vector<int> cols(grid[0].size(), 0);
        
        for (int i = 0; i < grid.size(); ++i) {
            int row = 0;
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1)
                    row++;
            }
            rows[i] = row;
        }
        
        for (int i = 0; i < grid[0].size(); ++i) {
            int col = 0;
            for (int j = 0; j < grid.size(); ++j) {
                if (grid[j][i] == 1)
                    col++;
            }
            cols[i] = col;
        }
        
        long long ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    ans += 1LL * ((rows[i] - 1) * (cols[j] - 1));
                }
            }
        }
        return ans;
    }
};


// public:
//     long long numberOfRightTriangles(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         vector<int> row(n, 0), col(m, 0);
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(grid[i][j]){
//                     row[i]++;
//                     col[j]++;
//                 }
//             }
//         }
//         long long ans = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(grid[i][j]){
//                     ans += 1LL * (row[i] - 1) * (col[j] - 1);
//                 }
//             }
//         }
//         return ans;
//     }
// };
