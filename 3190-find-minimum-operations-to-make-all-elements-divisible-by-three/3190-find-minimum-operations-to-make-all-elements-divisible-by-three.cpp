class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bool ans=false;
        int cnt=0;
        while(ans!=true){
            for(int i=0;i<nums.size();i++){
                int x= nums[i]%3;
                if(x==1){
                    nums[i]--;
                    cnt+=1;
                }
                else if(x==2){
                    nums[i]++;
                    cnt+=1;
                }
            }
            for(int i=0;i<nums.size();i++){
                if(nums[i]%3!=0)ans=false;
                else {
                    ans=true;
                }
            }
        }
        return cnt;
    }
};