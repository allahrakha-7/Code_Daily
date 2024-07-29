class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count = 0;
        
        for (int j = 0; j < rating.size(); j++) {
            int less_before = 0, greater_before = 0;
            int less_after = 0, greater_after = 0;

            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j]) {
                    less_before++;
                } else if (rating[i] > rating[j]) {
                    greater_before++;
                }
            }
            
            for (int k = j + 1; k < rating.size(); k++) {
                if (rating[k] < rating[j]) {
                        less_after++;
                    } else if (rating[k] > rating[j]) {
                        greater_after++;
                    }
                }
                count += less_before * greater_after;
                count += greater_before * less_after;
            }
        return count;
    }
};