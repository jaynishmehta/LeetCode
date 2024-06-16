class Solution {
public:
    int countCompleteDayPairs(vector<int>& h) {
        int cnt = 0; 
        
       
        for (int i = 0; i < h.size() - 1; i++) {
            int sum = h[i];  
            
           
            for (int j = i + 1; j < h.size(); j++) {
                int sum = h[i] + h[j];
                
                
                if (sum % 24 == 0) {
                    cnt++;  
                }
            }
        }
        
        return cnt; 
    }
};
