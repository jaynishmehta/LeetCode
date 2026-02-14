class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n= nums.size();
        int sum = 0;
        for(auto it:nums){
            sum+=it;
        }
        int ele=n-1,cnt=0;
        for(int i=0;i<n;i++){
            sum-= nums[i];
            double avg =(double)sum /ele;
            ele--;
            if(nums[i]>avg){
                cnt++;
            }
        }
        return cnt;
    }
};