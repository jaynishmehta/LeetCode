class Solution {
public:
    string reverseVowels(string s) {
        int n= s.size();
        int i=0;
        int j= n-1;
        while(i<j){
            char x= tolower(s[i]);//A-->a
            char y= tolower(s[j]);
            if((x=='a' || x=='e' || x=='i' || x=='o' || x=='u' ) && (y=='a' || y=='e' || y=='i' || y=='o' || y=='u') ){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u' ){
                j--;
            }
            else if(y=='a' || y=='e' || y=='i' || y=='o' || y=='u'){
                i++;
            }
            else{
                i++;
                j--;
            }
            
        }
        return s;

    }
};