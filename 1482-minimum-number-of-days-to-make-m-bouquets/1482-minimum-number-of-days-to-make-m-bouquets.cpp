class Solution {
    bool func(vector<int>& bloomd,int m, int k,int mid){
        long long int days=0;
        long long contin=0;
        for(int i=0;i<bloomd.size();i++){
            if(mid>=bloomd[i]){
                contin++;
                if(contin==k){
                    days++;
                    contin=0;
                }
            }
            else{
                contin=0;
            }
        }
        if(days>=m)return true;
        else return false;
    }
public:
    int minDays(vector<int>& bloomd, int m, int k) {
        if((long long)m*k>bloomd.size())return -1;
        long long int l=1;
        long long int h=*max_element(bloomd.begin(),bloomd.end());
        long long ans=-1;
        while(l<=h){
            long long mid= l+(h-l)/2;
            if(func(bloomd,m,k,mid)){
                ans=mid;
                h= mid-1;
            }
            else{
                l= mid+1;
            }
        }
        return ans;
    }
};