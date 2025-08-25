class Solution {
public:
    int solve(int a,int b){
        if(b==0)return a;
        return solve(b,a%b);
    }

    int gcdOfOddEvenSums(int n) {
        int s1 = 2* (n*(n+1)/2);
        int s2 = 1*(n) + 2*((n-1)*(n)/2);
        cout<<s1<<" "<<s2<<endl;
        return solve(s1,s2);
    }
};