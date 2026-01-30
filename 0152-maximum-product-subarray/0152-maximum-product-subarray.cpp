class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            int q= nums[i];
            int p=max(nums[i],nums[i+1]);
            maxi= max(maxi,p);
            for(int j=i+1;j<nums.size();j++){
                q*=nums[j];
                if(maxi<q)maxi=q;
            }
        }
        return maxi;
    }
};