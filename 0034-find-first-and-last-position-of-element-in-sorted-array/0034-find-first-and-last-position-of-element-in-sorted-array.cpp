#include<bits/stdc++.h>
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l= 0;
        int h= nums.size()-1;
        int p1=-1;
        int p2=-1;
        int mid;
        while(l<=h){
            mid=l+(h-l)/2;
            if(nums[mid]==target){
                // p1= min(mid,min(p1,p2));
                // p2= max(mid,max(p1,p2));
                // l=mid+1;
                // h= mid-1;
                if(mid>=1 && nums[mid-1]==target){
                    if(mid<nums.size()-1 && nums[mid+1]==target){
                        for(int i= mid;i<nums.size();i++){
                            if(nums[i]==target){
                                p2= max(i,p2);
                            }
                        }
                        // p2= max(mid+1,p2);
                        h=mid-1;
                    }
                    else{
                    p2= max(mid,p2);
                    h= mid-1;
                    }
                    // cout<<l<<" "<<h<<endl;
                }
                else{
                    p1= max(mid,p1);
                    l=mid+1;
                    // cout<<l<<" "<<h<<endl;
                }
            }
            else if(nums[mid]>target){
                h= mid-1;
            }
            else{
                l= mid+1;
            }
        }
        if(p1==-1 && p2!=-1)p1=p2;
        else if(p1!=-1 && p2==-1)p2=p1;
        vector<int>v={p1,p2};
        return v;
    }
};