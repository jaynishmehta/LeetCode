class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=INT_MIN;
        for(auto it:nums){
            if(it>maxi)maxi= it;
            
        }
        int cnt=1;
        int ans=0;
        // int prev=maxi;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi && (i>0) && (nums[i-1]==maxi)){
                cnt+=1;
                ans = max(ans,cnt);
            }
            else{
                cnt=1;
                ans= max(ans,cnt);
            }
        }
        return ans;
    }
};