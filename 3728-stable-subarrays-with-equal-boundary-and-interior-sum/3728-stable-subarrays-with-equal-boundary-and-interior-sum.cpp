class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        
        long long int cnt=0;
        long long sum=0,s1=0;
        map<pair<long long int,long long int>,long long int>m;
        for(int i=0;i<capacity.size();i++){
            sum+=capacity[i];
            cnt+=m[{sum-(2*capacity[i]),capacity[i]}];
            m[{sum,capacity[i]}]++;

            if(i-1>=0 && (capacity[i]==0 && capacity[i-1]==0))cnt--;
        }
        

    return cnt;
    }
        
    
};