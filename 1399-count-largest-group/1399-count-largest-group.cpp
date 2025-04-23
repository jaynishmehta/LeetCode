class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int>m;
        for(int i=1;i<=n;i++){
            int x=i;
            int sum=0;
            while(x>0){
                int temp = x%10;
                x/=10;
                sum+=temp;
            }
            m[sum]++;
        }
        int maxi=0;
        for(auto it:m){
            maxi= max(maxi,it.second);
        }
        int cnt=0;
        for(auto it:m){
            if(it.second==maxi)cnt++;
        }
        return cnt;
    }
};