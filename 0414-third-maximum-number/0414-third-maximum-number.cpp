class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long int a=-1e12;
        long long int b=-1e12;
        long long int c= -1e12;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>a){
                c=b;
                b=a;
                a=nums[i];
            }
            else if(nums[i]<a && nums[i]>b){
                c=b;
                b=nums[i];
            }
            else if(nums[i]<a && nums[i]<b && nums[i]>c){
                c=nums[i];
            }
        }
        if(c==-1e12)return a;
        return c;
    }
};