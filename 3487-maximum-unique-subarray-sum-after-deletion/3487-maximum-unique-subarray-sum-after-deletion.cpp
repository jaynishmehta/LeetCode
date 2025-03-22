class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>s;
        int m=-200;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            if(nums[i]>m)m=nums[i];
        }
        if(m<0)return m;
        int sum=0;
        int maxi=0;
        for(auto it:s){
            sum+=it;
            if(sum<=0){
                sum=0;
            }
            maxi= max(maxi,sum);
        }
        return maxi;
    }
};