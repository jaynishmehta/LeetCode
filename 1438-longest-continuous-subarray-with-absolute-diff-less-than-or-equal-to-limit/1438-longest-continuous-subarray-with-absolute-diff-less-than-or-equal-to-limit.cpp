class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0, j = 0;
        int mini = nums[0];
        int maxi = nums[0];
        int len = 1;
        
        while (j < nums.size()) {
            // Update the max and min for the current window
            mini = min(mini, nums[j]);
            maxi = max(maxi, nums[j]);
            
            // If the current window is valid, update the length
            if (maxi - mini <= limit) {
                len = max(len, j - i + 1);
                j++;
            } 
            else {
                if (nums[i] == maxi || nums[i] == mini) {
                    mini = INT_MAX;
                    maxi = INT_MIN;
                    for (int k = i + 1; k <= j; k++) {
                        mini = min(mini, nums[k]);
                        maxi = max(maxi, nums[k]);
                    }
                }
                i++;
                j++;
            }
        }
        
        return len;
    }
};
