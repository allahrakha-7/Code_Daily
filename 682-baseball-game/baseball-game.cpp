class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> allScores;

        int temp;
        
        int sumOfAllScores = 0;

        for (int i = 0; i < operations.size(); i++) {

            if (operations[i] != "C" && operations[i] != "D" && operations[i] != "+") {
                
                allScores.push(stoi(operations[i]));

            } else if (operations[i] == "C" && !allScores.empty()) {

                allScores.pop();

            } else if (operations[i] == "D") {

                temp = allScores.top() * 2;

                allScores.push(temp);

            } else if (operations[i] == "+") {

                int last = allScores.top();

                allScores.pop();

                int secondLast = allScores.top();

                allScores.push(last);

                allScores.push(last + secondLast);
            }
        }

        while (!allScores.empty()) {

            sumOfAllScores += allScores.top();

            allScores.pop();
        }
        return sumOfAllScores;
    }
};