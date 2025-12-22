class Solution {
public:
    bool search(int low,int high,int row,vector<vector<int>>& matrix, int target){
        
        while(low<=high){
            int mid = low+(high-low)/2;
            if(matrix[row][mid]==target)return true;
            if(matrix[row][mid]<target){
                low=mid+1;
            }
            else if(matrix[row][mid]>target){
                high=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,high =matrix.size()-1,n= matrix[0].size()-1;
        
        while(low<=high){
            int mid= low+(high -low)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][n]){
                return search(0,n,mid,matrix,target);
            }
            else if(target<=matrix[mid][0]){
                high=mid-1;
            }
            else if(target>=matrix[mid][n]){
                low=mid+1;
            }
        }
        return false;
    }
};