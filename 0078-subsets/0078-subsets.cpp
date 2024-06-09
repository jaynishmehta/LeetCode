class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        for(int i=0;i<(1<<nums.size());i++){
            vector<int>div;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)){
                    div.push_back(nums[j]);
                }
            }
            v.push_back(div);
        }
        return v;
    }
};