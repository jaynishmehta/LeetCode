class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi= max(maxi,nums[i]);
        }
        int i=0,j=0;
        long long int cnt=0;
        unordered_map<int,int>m;
        while(i<nums.size() && j <nums.size()){
            if(nums[j]==maxi){
                m[maxi]++;
            }
            if(m[maxi]>=k){
                cnt++; 
                int rem = nums.size()-(j+1);
                cnt+=rem;
                if(nums[i]==maxi){
                    m[maxi]--;
                }
                i++;
                if(nums[j]==maxi){
                    m[maxi]--;
                }
                j--;
            }
            j++;
        }
        return cnt;
    }
};