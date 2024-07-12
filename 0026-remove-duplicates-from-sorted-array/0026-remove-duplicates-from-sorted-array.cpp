class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int temp=nums[0];
        vector<int>v;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=temp){
                v.push_back(temp);
                temp=nums[i];
            }
        }
        v.push_back(temp);
        for(int i=0;i<v.size();i++){
            nums[i]=v[i];
        }
        return v.size();
    }
};