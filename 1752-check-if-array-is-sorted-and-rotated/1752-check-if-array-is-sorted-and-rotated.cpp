class Solution {
public:
    bool check(vector<int>& nums) {
        int bimp=0;
        int n= nums.size();
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1])bimp++;
        }
        if(nums[0]<nums[n-1])bimp++;
        
        return bimp<=1;
    }
};