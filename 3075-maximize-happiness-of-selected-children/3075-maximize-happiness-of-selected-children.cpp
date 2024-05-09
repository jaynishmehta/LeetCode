class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long sum=0;
        int i=1;
    
        while(k--){
            // sum+=(happiness[i-1]-i);
            if((happiness[i-1]-i)<0){
                sum+=0;
            }
            else{
                sum+=(happiness[i-1]-(i-1));
            }
            i++;
        }
        return sum;
        
    }
};