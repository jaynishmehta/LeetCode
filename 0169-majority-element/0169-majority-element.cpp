#include<bits/stdc++.h>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                m[nums[i]]+=1;
            }
            else{
                m[nums[i]]=1;
            }
        }
        int max =INT_MIN;
        int key=0;
        for(auto pair : m){
            if(pair.second>nums.size()/2){
                key= pair.first;
                return key;
            }
        }
        return -1;
    }
};