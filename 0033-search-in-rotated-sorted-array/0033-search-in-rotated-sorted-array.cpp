class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        int k = target;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid]==target)return mid;

            else if(nums[mid]>nums[h]){ //left is sorted
                if(nums[l]>k || nums[mid]<k){ // eliminate when k is small than lower or greater than greater
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }

            else{ //right is sorted - it will be eliminated in two case either greatest or smallest
                if(k>nums[h] || k< nums[mid])h=mid-1;
                
                else l=mid+1;
            }
            
        }
        return -1;
    }
};