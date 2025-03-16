class Solution {
public:
    bool pos(long long mid,vector<int>&ranks,int cars){
        long long int n=0;
        for(int i=0;i<ranks.size();i++){
            n+= sqrt(mid/ranks[i]);
            if(n>=cars)return true;
        }
        return false;
        
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long int low=1;
        long long int high = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;
        long long int ans=0;
        while(low<=high){
            long long int mid= low+ (high-low)/2;
            if(pos(mid,ranks,cars)){
                ans= mid;
                high= mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};