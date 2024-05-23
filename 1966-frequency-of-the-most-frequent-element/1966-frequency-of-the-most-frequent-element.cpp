class Solution {
public:
    int maxFrequency(vector<int>& n, int k) {
        int maxi=1;
        sort(n.begin(),n.end());
        int i=n.size()-1;
        // while(i>0){
            // int pointer=n[i];
            int j=i-1;
            long long sum=0;
            while(i>0 && j>=0){
                if((n[i]-n[j])<=k-sum){
                sum+=(n[i]-n[j]);
                maxi=max(maxi,((i-j+1)));
                if(j==0)break;
                j--;
                }
                else{
                    if(sum==0){
                        sum=0;
                    }
                    else{
                    sum-=(i-j-1)*(n[i]-n[i-1]);
                    }
                    i--;
                    // n[i]=n[i-1];
                    // break;
                }
                // [9952,9970,9982,9983,9985,9997] ,,, k=30
            }
            // i--;
        // }
        return maxi;
    }
};
// class Solution {
// public:
//     int maxFrequency(vector<int>& n, int k) {
//         int maxi = 1;
//         int i = n.size() - 1;
//         sort(n.begin(), n.end());
        
//         int pointer = n[i];
//         int j = i - 1;
//         long long sum = 0;

//         while (i > 0 && j >= 0) {
//             if ((pointer - n[j]) <= k - sum) {
//                 sum += (pointer - n[j]);
//                 maxi = max(maxi, (i - j + 1));
//                 if (j == 0) break;
//                 j--;
//             } else {
//                 sum -= (pointer - n[i]);
//                 cout<<pointer-n[i]<<endl;
//                 i--;
//                 pointer = n[i]; // Update the pointer to the new highest value in the window
//                 // j = i - 1; // Reset j to one position left of the new i
//             }
//         }

//         return maxi;
//     }
// };
