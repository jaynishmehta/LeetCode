class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        priority_queue<pair<pair<int,int>, pair<int, int>>, 
                       vector<pair<pair<int,int>, pair<int, int>>>, 
                       greater<>> q;
        vector<vector<int>>v(mt.size(),vector<int>(mt[0].size(),0));
        q.push({{0,2},{0,0}}); //{{time,steps},{x,y}}
        v[0][0]=1;
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        // int min=INT_MINI;
        int cnt=0;
        while(!q.empty()){
            int time = q.top().first.first;
            cout<<time<<" ";
            int steps= q.top().first.second;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
        
        if ((x == mt.size() - 1) && (y == mt[0].size() - 1)) {
                // cnt = min(cnt, time);
            // if(steps==2)return time+1;
            // else  return time+2;
                return time;
        }
         for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= mt.size() || ny >= mt[0].size() || v[nx][ny] != 0)continue;
                v[nx][ny] = 1;
                if(time>mt[nx][ny] && mt[x][y]>mt[nx][ny]){
                    // q.push({mt[nx][ny]+ 1, {nx, ny}});
                    if(steps==1)
                        q.push({{time+ 2,2}, {nx, ny}});
                    else
                        q.push({{time+ 1,1}, {nx, ny}});
                }
                else if(time>mt[nx][ny] && mt[x][y]<=mt[nx][ny]){
                    if(steps==1)
                        q.push({{time+ 2,2}, {nx, ny}});
                    else
                        q.push({{time+ 1,1}, {nx, ny}});
                }
                else{
                    if(steps==1)
                       q.push({{mt[nx][ny]+ 2,2}, {nx, ny}});
                    else
                       q.push({{mt[nx][ny]+ 1,1}, {nx, ny}});
                }
         }
    }
    return cnt;
    }
};