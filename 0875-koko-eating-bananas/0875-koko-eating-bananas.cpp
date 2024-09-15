class Solution {
    long long bond(vector<int>&piles,long long mid){
        long long sum=0;
        for(auto it:piles){
            sum+=ceil(double(it)/double(mid));
            // cout<<sum<<endl;
        }
        return sum;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low= 1;
        long long  high=0;
        int ans=0;
        int maxi=INT_MIN;
        for(auto it:piles){
            // high+=it;
            maxi = max(maxi,it);
        }
        high= maxi;
        while(low<=high){
            long long mid= low+(high-low)/2;
            long long x=bond(piles,mid);
            if(x<=h){
                ans= mid;
               high= mid-1;
                cout<<ans<<" ";
            }
            else{
                low= mid+1;
                
            }
        }
        return ans;
    }
};