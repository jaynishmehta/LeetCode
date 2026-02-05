class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n= nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<nums.size();i++){
           int idx = (i + nums[i]) % n;

            if(idx < 0) idx += n;   // handle negative wrap

            ans[i] = nums[idx];
        }
        return ans;
    }
};