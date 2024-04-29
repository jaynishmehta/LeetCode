#include<bits/stdc++.h>
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long xorr=0;
        for(int i=0;i<nums.size();i++){
            xorr^=nums[i];
        }
        int cnt=0;
        long long xor1=k^xorr;
        cout<<xor1;
        while(xor1!=0){
            if((xor1 & 1) ==1){
                cnt++;
                xor1=xor1>>1;
            }
            else{
                xor1=xor1>>1;
            }
            
        }
        return cnt;
    }
};