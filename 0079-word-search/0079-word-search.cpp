class Solution {
public:
    bool search(int i,int j,int m,int n,vector<vector<char>>& board, string word,int k){
        if(k==word.size())return true;
        if(i<0 || j<0 || i==m || j==n || board[i][j]!=word[k])return false;
        char ch =board[i][j];
        board[i][j]='#';
        bool op1 = search(i+1,j,m,n,board,word,k+1);
        bool op2 = search(i-1,j,m,n,board,word,k+1);
        bool op3 = search(i,j+1,m,n,board,word,k+1);
        bool op4 = search(i,j-1,m,n,board,word,k+1);
        board[i][j]=ch;
        return op1 || op2 ||op3 ||op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m= board.size();
        int n= board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(search(i,j,m,n,board,word,0))return true;
                }
            }
        }
        return false;
    }
};