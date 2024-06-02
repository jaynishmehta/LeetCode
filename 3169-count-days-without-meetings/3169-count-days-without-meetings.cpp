class Solution {
public:
    int countDays(int days, vector<vector<int>>& intervals) {
        // Sort the intervals by their start time
        sort(intervals.begin(), intervals.end());
        
        int totalCoveredDays = 0;
        int currentStart = intervals[0][0];
        int currentEnd = intervals[0][1];
        
        // Iterate through the intervals to merge overlapping ones and calculate the covered days
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= currentEnd) { // Overlapping intervals
                currentEnd = max(currentEnd, intervals[i][1]);
            } else {
                // Add the days covered by the current interval
                totalCoveredDays += (currentEnd - currentStart + 1);
                // Move to the next interval
                currentStart = intervals[i][0];
                currentEnd = intervals[i][1];
            }
        }
        // Add the days covered by the last interval
        totalCoveredDays += (currentEnd - currentStart + 1);
        
        // Calculate the remaining days
        int remainingDays = days - totalCoveredDays;
        return remainingDays;
    }
};
