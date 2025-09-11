class Solution {
public:
    string sortVowels(string s) {
        vector<char>v;
        for(int i=0;i<s.size();i++){
            char c= tolower(s[i]);
            if(c=='a'||c=='e'||c=='i'|| c=='o'||c=='u'){
                // ss.insert(s[i]);
                v.push_back(s[i]);
            }
        }
        sort(v.begin(),v.end());
        string t="";
        int k=0;
        for(int i=0;i<s.size();i++){
            char c= tolower(s[i]);
            if(c=='a'||c=='e'||c=='i'|| c=='o'||c=='u'){
                // s[i]=ss.top();
                // ss.pop();
                t+=v[k];
                k++;
            }
            else{
                // s[i]=s[i];
                t+=s[i];
            }
        }
        return t;
    }
};