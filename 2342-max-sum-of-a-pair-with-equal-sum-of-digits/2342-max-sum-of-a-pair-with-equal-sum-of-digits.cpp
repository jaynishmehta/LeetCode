class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>>m;
        for(int i=0;i<nums.size();i++){
            int temp=0;
            int x=nums[i];
            while(nums[i]){
                temp += (nums[i]%10);
                nums[i]/=10;
            }
            m[temp].push(x);
        }
        long long int maxi=-1;
        for(auto it:m){
            int cnt=0;
            long long int sum=0;
            while(!it.second.empty() && cnt<2){
                sum+=it.second.top();
                it.second.pop();
                cnt++;
            }
            if(cnt>=2)maxi = max(maxi,sum);
            
        }
        return maxi;
    }
};