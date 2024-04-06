class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size();
         int count  = 0;
        int l = 0;
        int r = 0;
        int maxLen = 0;
        while(r<n){
            if(nums[r]==0) count++;
            while(count>k){
                if(nums[l] == 0) count--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};
// int longestSubSeg(vector<int> &nums , int n, int k){

//    int count  = 0;

//         int l = 0;

//         int r = 0;

//         int maxLen = 0;

       

 

//         while(r<n){

//             if(nums[r]==0) count++;

 

//             while(count>k){

//                 if(nums[l] == 0) count--;

//                 l++;

//             }

 

//             maxLen = max(maxLen, r-l+1);

//             r++;

//         }

//         return maxLen;

// }