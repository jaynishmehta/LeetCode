class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>s;
        vector<int>l;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                s.push_back(nums[i]);
            }
            else if(nums[i]>pivot) l.push_back(nums[i]);
        }
        vector<int>ans;
        
        for(int i=0;i<s.size();i++)ans.push_back(s[i]);
        for(int i=0;i<nums.size()-(s.size()+l.size());i++)ans.push_back(pivot);
        for(int i=0;i<l.size();i++)ans.push_back(l[i]);
        return ans;
    }
};