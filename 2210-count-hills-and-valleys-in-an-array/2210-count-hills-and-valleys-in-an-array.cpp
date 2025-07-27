class Solution {
public:
    int countHillValley(vector<int>& num) {
        int cnt=0;
        vector<int>nums;
        vector<int> filtered;

        // Step 1: Remove consecutive duplicates
        nums.push_back(num[0]);
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] != num[i - 1]) {
                nums.push_back(num[i]);
            }
        }
        
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]){
                if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                    cnt++;
                }
                else if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){
                    cnt++;
                }
            }
            
        }
        return cnt;
    }
};