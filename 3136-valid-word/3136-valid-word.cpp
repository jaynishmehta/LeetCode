class Solution {
public:
    bool isValid(string w) {
        if(w.size()<3)return false;
        // tolower(w.begin(),w.end());
        transform(w.begin(), w.end(), w.begin(), ::tolower);

        bool v=false,c=false,d=true;
        for(auto it:w){
            if(it=='a' || it =='e'|| it=='i'||it=='o'||it=='u'){
                v=true;
            }
            else if(it-'0'>=0 && it-'0'<=9){
                d=true;
            }
            else if(it-'a'>=0 && it-'a'<=26){
                c=true;
            }
            else return false;
        }
        if(v && c && d)return true;
        return false;
    }
};