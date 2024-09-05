class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            // if(st.size()==0){
                
            // }
            
            if((it==')') && st.size()>0 && st.top()=='('){
                st.pop();
            }
            else if((it=='}')&& st.size()>0 && st.top()=='{'){
                st.pop();
            }
            else if((it==']')&& st.size()>0 && st.top()=='['){
                st.pop();
            }
            
            else{
                st.push(it);
            }
            
        }
        if(st.size()>0)return false;
        return true;
    }
};