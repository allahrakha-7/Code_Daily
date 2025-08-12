class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int> waitingDays;
        
        vector<int> result(temperatures.size(), 0);
        
        for (int i = 0; i < temperatures.size(); i++) {
            
            while (!waitingDays.empty() && temperatures[i] > temperatures[waitingDays.top()]) {
                
                int previousDay = waitingDays.top();

                waitingDays.pop();

                result[previousDay] = i - previousDay;
            
            }
            waitingDays.push(i);
        }
        return result;
    }
};