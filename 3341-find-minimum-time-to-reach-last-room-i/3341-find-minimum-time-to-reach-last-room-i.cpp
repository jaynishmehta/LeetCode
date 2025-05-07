class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        // queue<pair<int, pair<int, int>>> q;
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<>> q;
        vector<vector<int>> v(mt.size(), vector<int>(mt[0].size(), 0));
        q.push({0, {0, 0}});
        v[0][0] = 1;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int cnt = INT_MAX;

        while (!q.empty()) {
            int time = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();

            if ((x == mt.size() - 1) && (y == mt[0].size() - 1)) {
                // cnt = min(cnt, time);
                return time;
                // continue;
            }

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= mt.size() || ny >= mt[0].size() || v[nx][ny] != 0)
                    continue;
                v[nx][ny] = 1;
                if(time>mt[nx][ny] && mt[x][y]>mt[nx][ny]){
                    // q.push({mt[nx][ny]+ 1, {nx, ny}});
                    q.push({time+ 1, {nx, ny}});
                }
                else if(time>mt[nx][ny] && mt[x][y]<=mt[nx][ny]){
                    q.push({time+ 1, {nx, ny}});
                }
                else{
                    q.push({mt[nx][ny]+ 1, {nx, ny}});
                }

                // if (mt[x][y] > mt[nx][ny]) {
                //     q.push({min(time,mt[nx][ny]) + 1, {nx, ny}});
                // } 
                // else if(time>=mt[nx][ny]){
                //     q.push({time + 1, {nx, ny}});
                // }
                // else {
                //     q.push({mt[nx][ny] + 1, {nx, ny}});
                // }
            }
        }

        return cnt == INT_MAX ? -1 : cnt;
    }
};
