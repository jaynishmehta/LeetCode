class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
       if(n&1){ 
            int n1= n/2;
            for(int i=-n1;i<=n1;i++){
                ans.push_back(i);
            }
       }
       else{
        int n1=n/2;
        for(int i=-n1;i<=n1;i++){
            if(i==0)continue;
            ans.push_back(i);
        }
       
       }
         return ans;
    }
};