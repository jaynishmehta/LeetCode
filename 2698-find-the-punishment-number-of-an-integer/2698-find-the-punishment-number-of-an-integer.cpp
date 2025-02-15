class Solution {
public:
    bool check(int num,int target){
        if(num<target || target<0)return false;

        if(num==target)return true;
        return (check(num/10,target-(num%10)) || check(num/100,target-(num%100)) || check(num/1000,target-(num%1000)));
    
    }
    
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int sq= i*i;
            if(check(sq,i)){
                ans+=(sq);
            }
        }
        return ans;
    }
};