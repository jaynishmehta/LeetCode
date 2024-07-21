class Solution {
public:
    int minChanges(int n, int k) {
        int cnt=0;
        if(n==k)return 0;
        if(k>n)return -1;
        while(n>0){
            int x= n&1;
            int y = k&1;
            cout<<x<<y<<endl;
            if(x==1 && y==0){
                cnt++;
            }
            else if(x==0 && y==1)return -1;
           n= n>>1;
            k= k>>1;
        }
        if(cnt==0)return -1;
        return cnt;
        }
        
};