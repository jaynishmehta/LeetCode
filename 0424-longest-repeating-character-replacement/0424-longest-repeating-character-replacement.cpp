// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int i=0,j=0,nk=k;
//         int ans=1;
//         while(i<s.size() && j<s.size()){
//             char c=s[i];
//             if(s[i]!=s[j]){
//                 if(nk>0){
//                     nk--;
//                     ans= max(ans,(j-i+1));
//                     j++;
//                 }
//                 else{
//                     while((i+1<s.size()) && (s[i+1]==c)){
//                         i++;
//                     }
//                     c=s[i];
//                     j=i;
//                     nk=k;
//                 }

//             }
//             else{
//                 ans= max(ans,(j-i+1));
//                 j++;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();

        for(char c = 'A'; c <= 'Z'; c++) {

            int i = 0, j = 0;
            int nk = k;

            while(j < n) {

                if(s[j] != c) {
                    if(nk > 0) {
                        nk--;
                    }
                    else {
                        while(i < j && s[i] == c) {
                            i++;
                        }

                        i++;
                        nk++;
                        continue;
                    }
                }

                ans = max(ans, j - i + 1);
                j++;
            }
        }

        return ans;
    }
};