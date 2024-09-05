class Solution {
public:
    int search(vector<int>& nums, int k) {
        int l=0;
        int h= nums.size()-1;
        while(l<=h){
            int mid= (l+h)/2;
            if(nums[mid]==k)return mid;
            
            if(nums[mid]>nums[h]){ //left is sorted
                if(k>=nums[l] && k<nums[mid])h=mid-1;
                else l= mid+1;
            }
            else{
                if(k<=nums[h] && k>nums[mid])l=mid+1;
                else{
                    h= mid-1;
                }
            }
            
        }
        return -1;
    }
};