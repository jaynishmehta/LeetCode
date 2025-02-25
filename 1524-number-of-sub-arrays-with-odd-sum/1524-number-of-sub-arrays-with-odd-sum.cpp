class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD= 1000000007;
        int ans=0;
        int prefix=0;
        int e_count=1;
        int o_count=0;
        for(int i=0;i<arr.size();i++){
            prefix+=arr[i];
            if(prefix & 1){
                ans+=e_count;
                o_count++;

            }
            else{
                ans+=o_count;
                e_count++;
            }
            ans= ans%MOD;
        }
        return ans;
    }
};