// class Solution {
// public:
//     string removeOccurrences(string s, string p) {
//         stack<char>st;
//         st.push(s[0]);
//         int j=0;
//         int l=p.size()-1;
//         for(int i=1;i<s.size();i++){
//             if(s[i]==p[l]  && st.size()>=p.size()){
//                 int m=l;
//                 bool temp=true;
//                 string left="";
//                 while(!st.empty()){
//                     if(st.top()==p[m] && m>0){
//                         left+=p[m];
//                         m--;
//                         st.pop();
//                     }
//                     else if(st.top()==p[m] && m==0){
//                         m--;
//                         st.pop();
//                         temp=true;
//                         break;
//                     }
//                     else {
//                         temp= false;
//                         break;
//                     }
//                 }
//                 if(temp){
//                     for(int j=0;j<p.size();j++)st.pop();
//                 }
//                 else{
//                     for(int j=left.size()-1;j<=0;j--){
//                         st.push(left[j]);
//                     }
//                 }

//             }
//             else{
//                 st.push(s[i]);
//             }
//         }
//         // return "d";
//         string ans="";
//         while(!st.empty()){
//             ans+=st.top();
//             st.pop();
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
    
// };
class Solution {
public:
    string removeOccurrences(string s, string p) {
        while (s.find(p) != string::npos) {
            s.erase(s.find(p), p.size());
        }
        return s;
    }
};
