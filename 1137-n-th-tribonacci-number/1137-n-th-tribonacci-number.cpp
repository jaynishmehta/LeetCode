class Solution {
     int fun(int n){
        int first = 0, second = 1;
        int third = 1;
        if(n==0)return 0;
        else if(n==1)return 1;
        else if(n==2)return 1;
        else if(n>=3){
            for (int i = 3; i <=n; i++) 
            {
                int curr = first + second + third;
                first = second;
                second = third;
                third = curr;
            }
        }
        return third;
        
        
    }
public:
    int tribonacci(int n) {
        long int ans= fun(n);
        return ans;
    }
};