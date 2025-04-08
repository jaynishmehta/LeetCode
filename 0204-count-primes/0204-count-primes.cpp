class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        int cnt =0;
        vector<int> v(n,0);

        for(int i=2;i*i<n;i++){
            if(v[i]==0){
                for(int j= i*i;j<n;j+=i){
                    v[j]=1;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(v[i]==0){
                // cout<<i<<" ";
                cnt++;
            }
        }
        return cnt;

    }
    // bool isprime(int x){
    //     for(int i=2;i*i<=x;i++){
    //         if(x%i==0)return false;
    //     }
    //     return true;
    // }

    // int countPrimes(int n) {
    //     int sum=0;
    //     int cnt=0;
    //     if(n<2)return 0;
    //     for(int i=2;i<n;i++){
    //         if(isprime(i)){
    //             cout<<i<<" ";
    //             cnt++;
    //             sum+=i;
    //         }
    //     }
    //     cout<<endl;
    //     cout<<sum<<endl;
    //     return cnt;
    // }
};