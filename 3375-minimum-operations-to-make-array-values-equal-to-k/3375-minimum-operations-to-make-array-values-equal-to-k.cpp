class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<k)return -1;
            mp[nums[i]]++;
        }
        int cnt=0;
        for(auto it:mp){
            if(it.first>k)cnt++;
        }
        return cnt;
    }
};