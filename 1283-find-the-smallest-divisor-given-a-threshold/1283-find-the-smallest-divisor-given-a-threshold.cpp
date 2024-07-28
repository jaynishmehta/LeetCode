class Solution {
    bool func(vector<int>& nums, int threshold,int mid){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+= ceil((double(nums[i]))/double(mid));
        }
        if(cnt<=threshold)return true;
        else return false;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long int l=1;
        long long int h= *max_element(nums.begin(),nums.end());
        long long ans=0;
        while(l<=h){
            long long mid= l+(h-l)/2;
            if(func(nums,threshold,mid)){
                ans= mid;
                h= mid-1;
            }
            else{
                l= mid+1;
            }
        }
        return ans;
    }
};