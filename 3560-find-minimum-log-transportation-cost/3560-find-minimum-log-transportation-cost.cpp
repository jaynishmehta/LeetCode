class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long int cost=0;
        if(n>k){
            int t1= (n-k);
            int t2= n-t1;
            cost+= (long long)t1 * (long long)t2;
        }
        if (m>k){
            int t1= (m-k);
            int t2= (m-t1);
            cost+= (long long)t1 * (long long)t2;
        }
        return cost;
    }
};