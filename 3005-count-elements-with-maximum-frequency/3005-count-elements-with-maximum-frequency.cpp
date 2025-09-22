class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int pr=nums[0];
        unordered_map<int,int>m;
        int cnt=1;
        for(int i=1;i<nums.size();i++){
            if(pr==nums[i]){
                cnt++;
            }
            else{
                pr=nums[i];
                m[cnt]++;
                cnt=1;
            }
        }
        m[cnt]++;
        int ans=1;
        int fans=1;
        for(auto it:m){
            if(it.first>=ans){
                ans=it.first;
                fans=it.first*it.second;
            }
        }
        return fans;
    }
};