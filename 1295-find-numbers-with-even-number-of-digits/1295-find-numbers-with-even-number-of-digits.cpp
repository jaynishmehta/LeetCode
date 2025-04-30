class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int d=0;
            while(x){
                x/=10;
                d++;
            }
            if((d & 1)==0)cnt++;
        }
        return cnt;
    }
};