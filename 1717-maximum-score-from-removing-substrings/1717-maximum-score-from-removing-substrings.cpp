class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char>st;
        int ans=0;
        st.push(s[0]);
        if(x>y){
            for(int i=1;i<s.size();i++){
                if(s[i]=='b' && st.size()>0 && st.top()=='a'){
                    ans+=x;
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            string temp="";
            while (!st.empty()){
                temp+=st.top();
                st.pop();
            }
            reverse(temp.begin(),temp.end());
            st.push(temp[0]);
            for(int i=1;i<temp.size();i++){
                if(temp[i]=='a'  && st.size()>0 && st.top()=='b'){
                    st.pop();
                    ans+=y;
                }
                else{
                    st.push(temp[i]);
                }
            }
        }
        
        else {
            for(int i=1;i<s.size();i++){
                if(s[i]=='a' && st.size()>0 && st.top()=='b'){
                    ans+=y;
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            string temp="";
            while (!st.empty()){
                temp+=st.top();
                st.pop();
            }
            reverse(temp.begin(),temp.end());
            st.push(temp[0]);
            for(int i=1;i<temp.size();i++){
                if(temp[i]=='b' && st.size()>0 && st.top()=='a'){
                    st.pop();
                    ans+=x;
                }
                else{
                    st.push(temp[i]);
                }
            }
        }
        return ans;
    }
};