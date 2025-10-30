class Solution {
public:
    long long removeZeros(long long n) {
        string s= to_string(n);
        string ss="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                ss+=s[i];
            }
        }
        reverse(ss.begin(),ss.end());
        long long n1=0;
        long long int x=1;
        for(int i=0;i<ss.size();i++){
            n1+=(ss[i]-'0')*x;
            x*=10;
        }
        return n1;
    }
};