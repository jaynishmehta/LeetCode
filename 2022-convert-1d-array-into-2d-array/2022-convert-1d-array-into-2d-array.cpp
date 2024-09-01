class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        vector<vector<int>>v;
         int i=0,j=0;
        vector<int>temp;
        if(m*n!=o.size())return {};
        for(auto it:o){
            
            temp.push_back(it);
            i++;
            if(j>=m)return {};
            if(i==n && j<m){
                v.push_back(temp);
                temp={};
                i=0;
                j++;
            }
        }
        return v;
    }
};