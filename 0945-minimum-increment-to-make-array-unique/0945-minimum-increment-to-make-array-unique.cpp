class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int minRequired = nums[0]; // Start from the first element after sorting
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= minRequired) {
                cnt += (minRequired + 1) - nums[i];
                minRequired++; // Increment minRequired to the next unique value
            } else {
                minRequired = nums[i]; // Update minRequired to current element
            }
        }
        
        return cnt;
    }
};
