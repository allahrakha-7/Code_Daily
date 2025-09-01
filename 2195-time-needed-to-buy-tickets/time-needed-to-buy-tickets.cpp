class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int seconds = 0;

        for (int i = 0; i < tickets.size(); i++) {

            if (i <= k) {

                seconds = seconds + min(tickets[i], tickets[k]);

            } else {

                seconds = seconds + min(tickets[i], tickets[k] - 1);
            }
        }
        return seconds;
    }
};