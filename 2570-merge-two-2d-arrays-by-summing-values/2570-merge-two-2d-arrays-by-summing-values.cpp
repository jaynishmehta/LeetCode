class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>m;
        for(auto it:nums1){
            m[it[0]]=it[1];
        }
        for(auto it:nums2){
            m[it[0]]+= it[1];
        }
        vector<vector<int>>ans;
        for(auto it:m){
            ans.push_back({it.first,it.second});
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};