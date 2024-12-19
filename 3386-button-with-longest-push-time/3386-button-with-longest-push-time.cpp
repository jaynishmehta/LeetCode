class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& e) {
        priority_queue<pair<int, int>>pq;
        pq.push({e[0][1],e[0][0]});
        for(int i=1;i<e.size();i++){
            if(pq.top().first!=(e[i][1]-e[i-1][1])){
                 pq.push({(e[i][1]-e[i-1][1]),e[i][0]});
            }
            else if(pq.top().first==(e[i][1]-e[i-1][1])){
                if(pq.top().second>e[i][0]){
                    pq.pop();
                    pq.push({(e[i][1]-e[i-1][1]),e[i][0]});
                }
            }
        }
        int top= pq.top().second;
        return top;
        
    }
};