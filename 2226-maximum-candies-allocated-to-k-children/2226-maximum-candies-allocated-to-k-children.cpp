class Solution {
public:
     bool check(long long mid,vector<int>& c,long long k){
        if (mid == 0) return false;  
        long long int cnt=0;
        for(int i=0;i<c.size();i++){
             cnt += (c[i] / mid);  // Always count how many children can receive `mid` candies
                 if (cnt >= k) return true;  // Early exit if condition is met
        
              
            
        }
        if(cnt>=k)return true;
        else return false;
     }
    int maximumCandies(vector<int>& c, long long k) {
        long long sum = accumulate(c.begin(), c.end(), 0LL);
        if (sum < k) return 0;
        long long maxi=0;
        for(int i=0;i<c.size();i++){
            if(c[i]>maxi)maxi=c[i];
        }
        
        long long mid=0;
        long long int l=1;
        long long r= maxi;
        long long ans=0;
        while(l<=r){
            mid = (l+(r-l)/2);
            cout<<mid;
            if(check(mid,c,k)){
                ans= mid;
                l= mid+1;
            }
            else{
                r= mid-1;
                // ans= mid;
            }
        }
        return ans;
    }
};


