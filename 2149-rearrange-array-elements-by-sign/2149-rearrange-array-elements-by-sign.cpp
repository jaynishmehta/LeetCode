class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int p=0,q=0,r=0;
        while(r<n){
            if(r%2==0){
                while(p<n && nums[p]<0){
                    p++;                     
                }
                if(nums[p]>0){
                    // swap(nums[p],nums[r]);
                    int temp = nums[p];
                    for(int k = p; k > r; k--){
                        nums[k] = nums[k-1];   // shift instead of swap
                    }
                    nums[r] = temp;
                    r++;
                    p++;
                    // q=p;
                }
            }
            else{
                while(q<n && nums[q]>0){
                    q++;                     
                }
                if(nums[q]<0){
                    // swap(nums[q],nums[r]);
                    int temp= nums[q];
                    for(int k = q; k > r; k--){
                        nums[k] = nums[k-1];   // shift instead of swap
                    }
                    nums[r] = temp;
                    r++;
                    q++;
                    // p=q;
                }
            }
        }
        return nums;
    }
};