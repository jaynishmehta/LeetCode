class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            string s1="";
            for(int i=0;i<s.size()-1;i++){
                    int c1= (s[i]-'0');
                    int c2= s[i+1]-'0';
                    int x= (c1+c2)%10;
                    s1+=char(x);
                // s1+= char((s[i-1]-'0')+(s[i]-'0'))%10;
                // s1+=temp;
            }
            s=s1;
        }
        if(s.size()<2)return false;
        if(s[0]==s[1])return true;
        else return false;
    }
};