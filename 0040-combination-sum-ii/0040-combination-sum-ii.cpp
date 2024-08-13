class Solution {
     void bond(int i, int sum, int target, vector<int>& temp, vector<vector<int>>& ans, vector<int>& c){
        // vector<int>temp;
          if (sum == target) {
                ans.push_back(temp);
                return;
            }
            if (sum > target || i >= c.size()) return;

            // Include the current number and move to the next
            temp.push_back(c[i]);
            bond(i + 1, sum + c[i], target, temp, ans, c);
            temp.pop_back();

            // Skip duplicates
            while (i + 1 < c.size() && c[i] == c[i + 1]) ++i;

            // Exclude the current number and move to the next
            bond(i + 1, sum, target, temp, ans, c);
        }

        
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        int n=c.size();
        vector<int> temp;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        sort(c.begin(), c.end());
        vector<vector<int>>ans;
       bond(0, 0, target, temp, ans, c);
        return ans;
    }
};