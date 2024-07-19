class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Find the minimum value in each row
        for(int i = 0; i < rows; ++i) {
            int minVal = matrix[i][0];
            int minCol = 0;
            for(int j = 1; j < cols; ++j) {
                if(matrix[i][j] < minVal) {
                    minVal = matrix[i][j];
                    minCol = j;
                }
            }
            
            bool isLucky = true;
            for(int k = 0; k < rows; ++k) {
                if(matrix[k][minCol] > minVal) {
                    isLucky = false;
                    break;
                }
            }

            if(isLucky) {
                ans.push_back(minVal);
            }
        }

        return ans;
    }
};
