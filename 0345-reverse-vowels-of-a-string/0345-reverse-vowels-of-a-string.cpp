class Solution {
public:
    string reverseVowels(string s) {
        vector<char>v;
        for(auto it:s){
            char x= tolower(it);
            if(x=='a'){
                v.push_back(it);
            }
            if(x=='e'){
                v.push_back(it);
            }
            if(x=='i'){
                v.push_back(it);
            }
            if(x=='o'){
                v.push_back(it);
            }
            if(x=='u'){
                v.push_back(it);
            }
            
        }
        //i,e,e,a
        // a,e,e,i
        reverse(v.begin(),v.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            char x= tolower(s[i]);
            if(x=='a'){
                s[i]=v[j];
                j++;
            }
            if(x=='e'){
                s[i]=v[j];
                j++;
            }
            if(x=='i'){
                s[i]=v[j];
                j++;
            }
            if(x=='o'){
                s[i]=v[j];
                j++;
            }
            if(x=='u'){
                s[i]= v[j];
                j++;
            }
        }
        return s;
    }
};