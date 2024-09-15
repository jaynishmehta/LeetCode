class Solution {
    long long sumofsquare(int n){
        long long sum=0;
        while(n>0){
            sum+=((n%10)*(n%10));
            n= n/10;
        }
        return sum;
    }
    bool solve(int n){
        unordered_set<int>s;
        while(n!=1 && (s.find(n)==s.end())){
           s.insert(n);
            n= sumofsquare(n);
        }
        return n==1;
        
    }
public:
    bool isHappy(int n) {
        return solve(n);
    }
};