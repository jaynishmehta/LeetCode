class Solution {
public:
    string pushDominoes(string dom) {
        queue<pair<int,char>>q;
        for(int i=0;i<dom.size();i++){
            if(dom[i]!='.')q.push({i,dom[i]});
        }
        while(!q.empty()){
            pair<int,char>p= q.front();
            q.pop();
            int i=p.first;
            char d= p.second;

            if(d=='L' && i>0 && dom[i-1]=='.'){
                q.push({i-1,'L'});
                dom[i-1]='L';
            }
            else if(d=='R'){
                if(i+1<dom.size() && dom[i+1]=='.'){
                    if(i+2<dom.size() && dom[i+2]=='L')q.pop();
                    else{
                        q.push({i+1,'R'});
                        dom[i+1]='R';
                    }
                }
            }
        }
        return dom;
    }
};