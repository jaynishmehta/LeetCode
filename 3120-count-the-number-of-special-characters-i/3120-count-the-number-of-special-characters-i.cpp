class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>lower;
        map<char,int>upper;
        for(int i=0;i<word.size();i++){
            if(islower(word[i])){
                lower[word[i]]++;
            }
            else{
                upper[word[i]+32]++;
            }
        }
        int cnt=0;
        for(auto it:lower){
            if(upper.find(it.first)!=upper.end()){
                cnt++;
            }
        }
        return cnt;
    }
};