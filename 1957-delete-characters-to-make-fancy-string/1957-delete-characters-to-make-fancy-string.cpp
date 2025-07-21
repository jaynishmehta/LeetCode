class Solution {
public:
    string makeFancyString(string s) {
        string t="";
        t+=s[0];
        char prev= s[0];
        int cnt=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==prev){
                cnt++;
                if(cnt<=2){
                    t+=s[i];
                }
            }
            else{
                prev=s[i];
                cnt=1;
                t+=s[i];
            }
            
        }
        return t;
    }
};