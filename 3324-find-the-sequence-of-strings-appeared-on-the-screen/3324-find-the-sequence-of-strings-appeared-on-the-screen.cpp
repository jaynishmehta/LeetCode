class Solution {
public:
    vector<string> stringSequence(string t) {
        stack<char>st;
        for(int i=t.size()-1;i>=0;i--){
            st.push(t[i]);
        }
        vector<string>v;
        string s="";
        s+='a';
        v.push_back(s);
        int ind=0;
        while(st.size()!=0){
            
            if(s[ind]!=st.top()){
                s[ind]=((s[ind]-'a'+1)%26+'a');
            }
            else if(s[ind]==st.top() && (t.size()-s.size()>0)){
                ind++;
                st.pop();
                s+='a';
            }
            else{
                ind++;
                st.pop();
                break;
                // s+='a';
            }
            v.push_back(s);
        }
        return v;
    }
};