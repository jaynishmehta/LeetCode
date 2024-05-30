class Solution {
public:
    double myPow(double x, int n) {
        long long nn=n;
        if(nn<0)nn=nn*-1;
        double ans=1;
        while(nn){
            if(nn%2){
                ans*=x;
                nn-=1;
            }
            else{
                x*=x;
                nn/=2;
            }
        }
        if(n>0)return ans;
        else if(n==0)return 1;
        else return 1/ans;
    }
};