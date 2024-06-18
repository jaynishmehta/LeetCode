// class Solution {
// public:
//     int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
//         vector<pair<int,int>>p;
//         for(int i=0;i<profit.size();i++){
//             p.push_back({difficulty[i],profit[i]});
//         }
//         sort(p.begin(),p.end());
//         sort(worker.begin(),worker.end());
//         int low=0;
//         long long sum=0;
//         int high = difficulty.size()-1;
//         for(int i=0;i<worker.size();i++){
//             int wage=0;
//             while(low<=high){
//                 int mid= (low+high)/2;
//                 if(worker[i]>p[mid].first){
//                     wage=p[mid].second;
//                     // continue;
//                     break;
//                 }
//                 else if(worker[i]>p[mid].first){
//                     wage=p[mid].second;
//                     high= mid-1;
//                 }
//                 else{
//                     low= mid+1;
//                 }
//             }
//             sum+=wage;
//         }
//         return sum;
//     }
// };
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < profit.size(); ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int maxProfit = 0;
        int sum = 0;
        int jobIndex = 0;

        for (int w : worker) {
            while (jobIndex < jobs.size() && jobs[jobIndex].first <= w) {
                maxProfit = max(maxProfit, jobs[jobIndex].second);
                ++jobIndex;
            }
            sum += maxProfit;
        }

        return sum;
    }
};
