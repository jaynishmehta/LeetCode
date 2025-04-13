# define MOD 1000000007
class Solution {
public:
    long long pow(long long a,long long b){
    if(b==0) return 1;

    long long half_power= pow(a,b/2);
    if(b%2 ==0)
    return half_power*half_power % MOD;

    else
    return half_power*half_power % MOD * (a % MOD) % MOD ;
    }
    int countGoodNumbers(long long n) {
        long long p1=0; // no of even index
        long long p2=0;  //no of  odd index
        if(n%2==1){
            p1=(n+1)/2;
            p2=n/2;
        }
        else{
            p1=n/2;
            p2=n/2;
        }
        //0,1,2,3,4,5,6,7,8,9
        return ((pow(5,p1)%MOD)*(pow(4,p2)%MOD)%MOD); // 5even bet (0-9) , 4 prime number btw 0-9
    }
};