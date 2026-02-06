class Solution {
    bool check(int m,vector<int>&nums){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==m){
                cnt++;
            }
            if(cnt>nums.size()/3)return true;
        }
        return false;
    }
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int t1=nums[0];
        set<int>s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])==s.end()){
                if(check(nums[i],nums)){
                    ans.push_back(nums[i]);
                    s.insert(nums[i]);
                }
            }
        }
        return ans;
    }
};