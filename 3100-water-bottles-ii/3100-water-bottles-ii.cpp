class Solution {
public:
    int maxBottlesDrunk(int botal, int exh) {
        int empty_bottle= botal;
        int ans= botal;
        botal=0;
        while((botal+empty_bottle>=exh)){
            if(botal>=1){
                botal-=1;
                ans+=1;
                empty_bottle+=1;
            }
            else{
                empty_bottle-= exh;
                exh+=1;
                botal+=1;
            }
            cout<<botal<<" "<<empty_bottle<<" "<<exh<<" "<<ans<<endl;
        }
        if(botal>0)ans+=botal;
        return ans;
    }
};