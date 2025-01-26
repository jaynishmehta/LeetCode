class Solution {
public:
    string longestPalindrome(string s) {
        int leftindex=0;
        int len=0;
        for(int i=0;i<s.size();i++){
            int j=i,k=i;
            while(j>=0 && k<s.size() && s[j]==s[k]){
                if(k-j+1 > len){
                    leftindex=j;
                    len = k-j+1;
                    
                }
                j--;
                k++;
            }
            // even palindrome
            j=i,k=i+1;
            while(j>=0 && k<s.size() && s[j]==s[k]){
                if(k-j+1 > len){
                    leftindex=j;
                    len = k-j+1;

                }
                j--;
                k++;
            }
        }
        return s.substr(leftindex,len);
    }
};