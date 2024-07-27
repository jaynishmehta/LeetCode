class Solution {
    bool func(vector<int>& piles,long long int mid,long long int h){
        long long time=0;
        for(int i=0;i<piles.size();i++){
            time+= ceil(double(piles[i])/double(mid));
        }
       if(time<=h)return true;
        else return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int low= 1;
        long long int high= 1;
        long long ans=1;
        for(int i=0;i<piles.size();i++){
           if(high<piles[i])high=piles[i];
        }
        while(low<=high){
            long long mid= low+(high-low)/2;
            long long x= func(piles,mid,h);
            
            if(x==0){
                low= mid+1;
            }
            else{
                high=mid-1;
                ans= mid;
            } 
        }
        return ans;
    }
};