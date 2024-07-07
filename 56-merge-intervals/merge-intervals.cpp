class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
        {
            return {};
        }

        sort (intervals.begin(), intervals.end());

        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);

        for (const auto interval : intervals)
        {
            vector<int>& lastInterval = mergedIntervals.back();

            if (interval[0] <= lastInterval[1])
            {
                lastInterval[1] = max(lastInterval[1], interval[1]);
            } else {
                mergedIntervals.push_back(interval);
            }
        }
        return mergedIntervals;
    }
};