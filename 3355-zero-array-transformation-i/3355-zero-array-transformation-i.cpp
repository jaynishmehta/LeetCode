class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        // vector<int>v(nums.size(),0);
        // for(int i=0;i<q.size();i++){
        //     int j=q[i][0],k=q[i][1];
        //     for(int l=j;l<=k;l++){
        //         if(nums[l]==0)continue;
        //         else{
        //             nums[l]--;
        //         }  
        //     }
        // }
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]!=0)return false;
        // }
        // return true;
        vector<int>diff(nums.size(),0);
 //step--1;
        for(int i=0;i<q.size();i++){
            int j= q[i][0] ,k =q[i][1];
            diff[j]+=1;
            if(k+1<nums.size()){
                diff[k+1]-=1;
            }

        }
    //step-2; prefix sum
    vector<int>ans(nums.size(),0);
    int temp=0;
    for(int i=0;i<diff.size();i++){
        temp+=diff[i];
        ans[i]=temp;
    }
    //step-3; compare original and ans vector;
    for(int i=0;i<ans.size();i++){
        if(ans[i]<nums[i])return false;
    }
    return true;
    }
};