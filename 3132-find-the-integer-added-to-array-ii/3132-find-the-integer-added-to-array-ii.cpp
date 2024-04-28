
using namespace std;

class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums2.begin(), nums2.end());
        int n = nums1.size();
        int m = nums2.size();
        int min_x = INT_MAX;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<int> v;
                
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) {
                        v.push_back(nums1[k]);
                    }
                }

                sort(v.begin(), v.end());
                bool valid = true;
                int x = nums2[0] - v[0];  

                for (int k = 1; k < m; ++k) {
                    if (nums2[k] - v[k] != x) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    min_x = min(min_x, x);
                }
            }
        }

        return min_x;
    }
};
