class Solution {
public:
    string largestGoodInteger(string num) {
        int cnt=1;
        string temp="";
        for(int i=0;i<num.size()-1;i++){
            if(num[i]==num[i+1]){
                cnt++;
                if(cnt==3){
                    string ans="";
                    ans+=num[i];
                    ans+=num[i];
                    ans+=num[i];
                    if(ans[0]>temp[0])temp=ans;
                    
                    cnt=1;
                }
            }
            else{
                cnt=1;
            }
        }
        return temp;
    }
};