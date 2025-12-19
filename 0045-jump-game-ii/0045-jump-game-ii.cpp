class Solution {
    // [7,0,9,6,9,6,1,7,9,0,1,2,9,0,3]
    // -,-------------,-------------
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currEnd = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == currEnd) {
                jumps++;
                currEnd = farthest;
            }
        }

        
        return jumps;
    }
};