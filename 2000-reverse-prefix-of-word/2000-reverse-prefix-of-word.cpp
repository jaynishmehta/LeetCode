class Solution {
public:
    string reversePrefix(string word, char ch) {
         int k=0;
        int j=0;
        string s="";
        int cnt=0;
        for(int i=0;i<word.size();i++){
            if(word[i]==ch && cnt==0){
                s+=word[i];
                reverse(s.begin(),s.end());
                cnt=1;
            }
            else{
                s+=word[i];
            }
        }
        return s;
    }
};