class Solution {
public:
    bool check(int t){
        while(t){
            int u= t%10;
            if(u==0)return false;
            t/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        for(int i=1;i<n;i++){
            int t1=i,t2=n-i;
            if(check(t1)&& check(t2)){
                ans.push_back(t1);
                ans.push_back(t2);
                break;
            }
        }
        return ans;
    }
};