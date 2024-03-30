class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            if (m.find(complement) != m.end()) {
                // Found a pair of indices that add up to the target
                v.push_back(m[complement]); // Index of complement
                v.push_back(i); // Current index
                break; // We found the answer, so exit the loop
            }

            // Store the current number and its index in the map
            m[nums[i]] = i;
        }
        return v;
    }
};