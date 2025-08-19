class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int cnt=0;
        int p=1;
        if(nums[0]==0)p=0;
        for(int i=1;i<nums.size();i++){
            // if(i ==nums.size() && nums[i]==0){
            //     int j = i-p+1;
            //     cout<<j<<endl;
            //     cnt+= (j*(j+1)/2);
            // }
            if(nums[i-1]==0 && nums[i]==0 )continue;
            else if(nums[i-1]==0 && nums[i]!=0){
                long long int j = i-1-p+1;
                cout<<j<<endl;
                cnt += ((j*(j+1))/2);
            }
            else if(nums[i-1]!=0 && nums[i]==0){
                p=i;
            }
            
        }
        if(nums[nums.size()-1]==0){
           long long  int j= nums.size()-1 -p+1;
            cnt+= (j*(j+1)/2);
        }
        
        return cnt;
    }
};