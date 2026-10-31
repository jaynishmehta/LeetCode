class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        int i=0,j=1;
        vector<int>v(2,0);
        while((i<=j) && (j<nums.size())){
            if(nums[i] == k-nums[j]){
                v[0]=i+1;
                v[1]=j+1;
                return v;
            }
            if(nums[i] + nums[j]< k){
                if(j+1 < nums.size() && (nums[j+1] +nums[i]<=k))j++;
                else i++;
            }
            else {
                
                if(i+1 < j && nums[i+1]+nums[j]>k)j--;
                else i++;
            }
        }
        return v;
    }
};