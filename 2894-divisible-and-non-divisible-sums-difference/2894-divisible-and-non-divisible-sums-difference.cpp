class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total_sum = n*(n+1)/2;
        int sum_div=0;
        for(int i=0;i<=n;i++){
            if(i%m==0)sum_div+=i;
        }
        int not_div = total_sum-sum_div;
        return not_div-sum_div;

    }
};