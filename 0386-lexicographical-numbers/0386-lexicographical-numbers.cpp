class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>v;
        int count=1;

        for(int i=0;i<n;i++){
            v.push_back(count); //push cnt each time according to lexi
            if(count * 10<=n){
                count*=10;      //count get incresed to count*10 next lexi numbber
            }
            else{
                if(count>=n)count/=10;  // if exceeds,like 100,then 100/10=10,
                count++;                //then 10+1=11,next lexi num
                while(count%10==0)count/=10; //eg. when cnt=20 , it will change it to 2
               
            }
        }
        return v;

    }
};