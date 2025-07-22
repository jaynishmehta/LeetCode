class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int j=0;
        int sum=0;
        int maxsum=0;
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            while(s.find(nums[i])!=s.end()){
                sum-=nums[j];
                s.erase(nums[j]);
                j++;
            }
            sum+=nums[i];
            s.insert(nums[i]);
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};