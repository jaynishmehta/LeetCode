class Solution {
public:
    string robotWithString(string s) {
        char min_c='a';
        stack<char>st;
        vector<int>freq(26,0);
        string ans="";
        for(auto it: s){
            freq[it-'a']++;
        }
        for(auto it:s){
            st.push(it);
            freq[it-'a']--;
            
            while(min_c <='z' && freq[min_c-'a']==0){
                min_c++;
            }

            while(!st.empty() && st.top()<= min_c){
                ans+=st.top();
                st.pop();
            }


        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};