class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<long long int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        // int smalle
        int cnt=1;
        int maxi=0;
        for(auto it:m){
           int x= it.first;
            if(m.find(x+1)!=m.end()){
                cnt++;
            }
            else{
                cnt=1;
            }
            maxi= max(maxi,cnt);
        }
        return maxi;
    }
};