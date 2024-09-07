class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int a1= c1[0]-'a';
        int a2= c1[1]-'1';
        int col1=1,col2=1;
        if((a1+a2)%2==0)col1=0;
        int b1=c2[0]-'a';
        int b2=c2[1]-'1';
        if((b1+b2)%2==0)col2=0;
        if(col1==col2)return true;
        else return false;
    }
};