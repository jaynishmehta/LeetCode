class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ev;
        vector<int>od;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)od.push_back(nums[i]);
            else ev.push_back(nums[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums.size()/2;i++){
            ans.push_back(ev[i]);
            ans.push_back(od[i]);
        }
        return ans;
    }
};