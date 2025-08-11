class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        vector<int>ans;
        vector<int>power;
        int t=1;
        while(t<=n){
            if(n&t){
                power.push_back(t);
            }
            t=t<<1;
        }
        long long int mod = 1e9+7;
        for(int i=0;i<power.size();i++)cout<<power[i]<<" ";
        for(int i=0;i<q.size();i++){
            long long pr=1;
            if(q[i][0]==q[i][1]){
                pr*=power[q[i][0]];
            }
            else{
                // pr*= power[q[i][0]];
                // pr*= power[q[i][1]];
                for(int j= q[i][0];j<=q[i][1];j++){
                    pr = (pr * power[j]) % mod;
                }
            }
            ans.push_back((pr%mod));
        }
        return ans;
    }
};