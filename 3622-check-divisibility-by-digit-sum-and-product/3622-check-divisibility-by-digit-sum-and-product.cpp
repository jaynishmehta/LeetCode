class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int pro=1;
        int m=n;
        while(m){
            int x = m%10;
            m/=10;
            sum+=x;
            pro*=x;
        }
        if(n%(pro+sum)==0)return true;
        else return false;
    }
};