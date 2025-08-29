class Solution {
public:
    long long flowerGame(int n, int m) {
        if(n==1 && m==1)return 0;
        int sum=1;
        long long int ans1=0;
        long long int ans2=0;
        long long int e=0;
        long long int o=0;
        if(n%2==0 && m%2!=0){
        e=n/2;
         o=m/2+1;
            ans1=o*e;
            o=0;
            e=0;
            o=n/2;
            e=m/2;
            ans2=o*e;
            
        }
        else if(n%2!=0 && m%2==0){
            e=m/2;
         o=n/2+1;
            ans1=o*e;
            o=0;
            e=0;
            o=n/2;
            e=m/2;
            ans2=o*e;
        }
        else if(n%2==0 && m%2==0){
            e=n/2;
            o=m/2;
            ans1=e*o;
            o=0;e=0;
            e=m/2;
            o=n/2;
            ans2=e*o;
        }
        else{
            e=n/2;
            o=m/2+1;
            ans1=e*o;
            e=0;
            o=0;
            o=n/2+1;
            e=m/2;
            ans2=e*o;
        }
        return ans1+ans2;
    }
};