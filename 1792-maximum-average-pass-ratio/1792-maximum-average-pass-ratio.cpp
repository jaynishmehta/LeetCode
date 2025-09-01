class Solution {
public:

    double maxAverageRatio(vector<vector<int>>& c, int extr) {
        auto gain = [](int a, int b) {
            return (double)(a+1)/(b+1) - (double)a/b;
        };

        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;
        for(int i=0;i<c.size();i++){
            pq.push({-gain(c[i][0], c[i][1]), {c[i][0], c[i][1]}});

        }
        while(extr){
            auto it = pq.top(); pq.pop();
            int a = it.second.first, b = it.second.second;
            a++, b++;
            pq.push({-gain(a, b), {a, b}});
            extr--;
        }
        double avg=0;
        int size = pq.size();
        while (!pq.empty()) {
            auto [negGain, p] = pq.top(); pq.pop();
            avg += (double)p.first / p.second;
        }
        return (double)avg/size;
    }
};