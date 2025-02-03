class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi=1;
        int inc_c=1;
        int dec_c=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]>0){
                inc_c++;
                maxi= max(maxi,inc_c);
            }
            else inc_c=1;
            if(nums[nums.size()-1-i]- nums[nums.size()-2-i]<0){
                dec_c++;
                maxi = max(maxi,dec_c);
            }
            else dec_c=1;
        }
        return maxi;
    }
};