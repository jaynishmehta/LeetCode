class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(st.size()==0)st.push(s[i]);
            else if(s[i]==')' && st.top()=='(')st.pop();
            else st.push(s[i]);
            
        }
        return st.size();
    }
};