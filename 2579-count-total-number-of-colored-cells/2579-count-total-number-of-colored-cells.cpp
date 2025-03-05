class Solution {
public:
    long long coloredCells(int n) {
        if(n==1)return 1;
        long long temp=0;
        long long n1= n-1;
        temp = n1*(n1+1)/2;
        temp*=4;
        return temp+1;
    }
};