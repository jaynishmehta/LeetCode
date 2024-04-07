// class Solution {
// public:
//     string makeGood(string s) {
//         while(s.size()>0){
            
//             for(int i=0;i<s.size()-1;i++){
//                 if((s[i] = s[i] + 32)|| (s[i]+32=s[i])){
//                     s.erase(i,1);
//                     s.erase(i,1);
//                 }
//             }
//         }
//     }
// };
class Solution {
 public:
  string makeGood(string s) {
    string ans;
    for (const char c : s)
      if (!ans.empty() && isBadPair(ans.back(), c))
        ans.pop_back();
      else
        ans.push_back(c);
    return ans;
  }

  bool isBadPair(char a, char b) {
    return a != b && tolower(a) == tolower(b);
  }
};