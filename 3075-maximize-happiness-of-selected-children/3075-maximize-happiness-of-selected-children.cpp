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
                cout<<"a"<<happiness[i-1]<<endl;
            }
            else{
                sum+=(happiness[i-1]-(i-1));
                cout<<"b"<<happiness[i-1]<<endl;
                cout<<"sum"<<sum<<endl;
            }
            i++;
        }
        return sum;
        
    }
};