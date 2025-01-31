class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int>v;
        while(n>0){
            v.push_back(n&1);
            n= n>>1;
        }
        int x= 32-v.size();
        for(int i=0;i<x;i++)v.push_back(0);
        long long ans=0;
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[32-i-1]<<" ";
            ans+=(v[i]*pow(2,i));
        }
        return ans;
    }
};