class Solution {
public:
    int minOperations(vector<int>& nums) {
        // int hc=0;
        int cnt1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)cnt1++;
        }
        if(cnt1>0)return nums.size()-cnt1;


        int min_l=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int gc=nums[i];
            for(int j=i+1;j<nums.size();j++){
                gc = gcd(nums[j],gc);
                if(gc==1){
                    min_l= min(min_l,(j-i+1));
                    cout<<min_l;
                }
            }
        }

        if(min_l!=INT_MAX){            
            return nums.size()-1+min_l-1;
        }
        return -1;
        
    }
};