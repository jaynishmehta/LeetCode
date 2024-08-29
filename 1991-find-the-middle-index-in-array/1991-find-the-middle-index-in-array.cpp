class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        long long sum=0;
        for(auto it:nums)sum+=it;
        long long s1=0;
        for(int i=0;i<nums.size();i++){
            s1+=nums[i];
            if(s1==sum)return i;
            sum-=nums[i];
            
        }
        return -1;
    }
};