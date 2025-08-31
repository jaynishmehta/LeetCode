class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        for(int i=0;i<9;i++){
            set<char>s1, s2;
            for(int j=0;j<9;j++){
                if(b[i][j]!='.'){
                    if(s1.count(b[i][j]))return false;
                    s1.insert(b[i][j]);
                }
            }
            for(int j=0;j<9;j++){
                if(b[j][i]!='.'){
                    if(s2.count(b[j][i]))return false;
                    s2.insert(b[j][i]);
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                set<char>box;
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        char val = b[3*i+k][3*j+l];
                        if(val!='.'){
                            if(box.count(val))return false;
                            box.insert(val);
                        }
                    }
                }
            }
        }
        return true;
    }
};
