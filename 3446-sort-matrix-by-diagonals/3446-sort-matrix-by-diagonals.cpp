class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& g) {
        int row=g.size(),col= g[0].size();
        int r=0,c=col-1;
        int t=0;
        int cnt=col-1;
        int cnt_y= 0;
        while(row*col>t){
            vector<int>v;
            while((r<row && c<col)&& (r<c)){
                v.push_back(g[r][c]);
                r++;
                c++;
                t++;
                
            }
            if(c>=col ){
                sort(v.begin(),v.end());
                int i=0;
                r=0,c=cnt;
                while(r<row && c<col){
                    g[r][c]=v[i];
                    r++,c++;
                    i++;
                }
                v.clear();
                cnt--;
                r=0;
                c=cnt;
            }
            v.clear();
            while((r<row && c<col)&& (r>=c)){
                v.push_back(g[r][c]);
                r++;
                c++;
                t++;
            }
            if(r>=row){
                sort(v.begin(),v.end(),greater<int>());
                int i=0;
                r=cnt_y,c=0;
                while((r<row && c<col)&& (r>=c)){
                    g[r][c]=v[i];
                    i++;
                    r++;
                    c++;
                }
                cnt_y++;
                r=cnt_y;
                c=0;
                v.clear();
            }
        }
        return g;
    }
};
// class Solution {
// public:
//     vector<vector<int>> sortMatrix(vector<vector<int>>& g) {
//         int row = g.size(), col = g[0].size();
//         int r = 0, c = col - 1;
//         int t = 0;
//         int cnt = col - 1;
//         int cnt_y = 0;

//         while (t < row * col) {
//             vector<int> v;

//             // collect top-right diagonals
//             while ((r < row && c < col) && (r < c)) {
//                 v.push_back(g[r][c]);
//                 r++;
//                 c++;
//                 t++;
//             }
//             if (c >= col) {
//                 sort(v.begin(), v.end());  // ascending
//                 int i = 0;
//                 r = 0; c = cnt;
//                 while (r < row && c < col) {
//                     g[r][c] = v[i++];
//                     r++, c++;
//                 }
//                 v.clear();
//                 cnt--;
//                 r = 0; c = cnt;
//             }

//             // collect bottom-left diagonals
//             v.clear();
//             while ((r < row && c < col) && (r >= c)) {
//                 v.push_back(g[r][c]);
//                 r++;
//                 c++;
//                 t++;
//             }
//             if (r >= row) {
//                 sort(v.begin(), v.end(), greater<int>());  // descending
//                 int i = 0;
//                 r = cnt_y; c = 0;
//                 while ((r < row && c < col) && (r >= c)) {
//                     g[r][c] = v[i++];
//                     r++, c++;
//                 }
//                 v.clear();
//                 cnt_y++;
//                 r = cnt_y; c = 0;
//             }
//         }
//         return g;
//     }
// };
