class Solution {
public:
    double triangleArea(vector<int>& A, vector<int>& B, vector<int>& C) {
        return 0.5 * abs(A[0] * (B[1] - C[1]) +
                         B[0] * (C[1] - A[1]) +
                         C[0] * (A[1] - B[1]));
    }
    double largestTriangleArea(vector<vector<int>>& p) {
        double ans=INT_MIN;
        for(int i=0;i<p.size()-2;i++){
            for(int j=i+1;j<p.size()-1;j++){
                for(int k=j+1;k<p.size();k++){
                    ans= max(ans, triangleArea(p[i],p[j],p[k]));
                }
            }
        }
        return ans;
    }
};