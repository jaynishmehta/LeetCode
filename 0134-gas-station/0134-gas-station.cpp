class Solution {
public:
    long long sum(vector<int>&v){
        long long ans=0;
        for(auto it:v)ans+=it;
        return ans;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(sum(gas)<sum(cost))return -1;
        int res=0;
        int total=0;
        for(int i=0;i<gas.size();i++){
            total+= (gas[i]-cost[i]);
            if(total<0){
                total=0;
                res=i+1;
            }
        }
        return res;
    }
};