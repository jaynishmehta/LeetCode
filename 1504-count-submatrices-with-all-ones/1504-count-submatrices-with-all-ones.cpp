class Solution {
public:
    int onefilledsubarray(vector<int>&v){
        long long cnt=0;
        long long contg=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==1){
                contg++;
                cnt+=contg;
            }
            else contg=0;
        }
        return cnt;
    }
    int numSubmat(vector<vector<int>>& mat) {
        //we will use pb-2348 in similar way starting from single row.
        long long ans=0;
        for(int i=0;i<mat.size();i++){
            vector<int>v(mat[0].size(),1);//to take & store the values in 1d form
            for(int j=i;j<mat.size();j++){
                for(int col=0;col<mat[0].size();col++){
                    v[col]=(v[col]&mat[j][col]);
                }
                ans+=onefilledsubarray(v); //pb-2348
            }

        }
        return ans;
    }
};