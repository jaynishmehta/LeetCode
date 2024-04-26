#include<bits/stdc++.h>
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt_dec=1;
        int cnt_inc=1;
        int maxi=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i] >0){
                cnt_inc++;
                maxi= max(maxi,cnt_inc);
            }
            else{
                cnt_inc=1;
            }
            
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]<0){
                cnt_dec++;
                maxi= max(maxi,cnt_dec);
            }
            else{
                cnt_dec=1;
            }
        }
        return maxi;
    }
};