class Solution {
public:
    int subsetXORSum(vector<int>& n) {
        int sum=0;
        for(int i=0;i<(1<<n.size());i++){
            int xorr=0;
            for(int bit=0;bit<n.size();bit++){
                if(i&(1<<bit)){
                    xorr^=n[bit];
                }
            }
            
            sum+=xorr;
            cout<<endl;
            }
        
        return sum;
    }
};