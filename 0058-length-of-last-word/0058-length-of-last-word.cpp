class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size();
        i--;
        char prev='1';
        int ans=0;
        while(i>=0){
            if(s[i]==' ' && prev=='1'){
                i--;
                prev='1';
            }
            else if(s[i]!=' ' && (prev=='1' || (prev!=' ' && prev!='1'))){
                prev=s[i];
                ans++;
                i--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};