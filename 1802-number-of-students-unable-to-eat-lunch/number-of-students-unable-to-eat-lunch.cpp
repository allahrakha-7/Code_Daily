class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count1 = count(students.begin(), students.end(), 0);
        int count2 = students.size() - count1;

        for (int i = 0; i < sandwiches.size(); i++)
        {
            if (sandwiches[i] == 0)
            {
                if (count1 > 0)
                {
                    --count1;
                } else {
                    return count1 + count2;
                }
            } else {
                if (count2 > 0)
                {
                    --count2;
                } else {
                    return count1 + count2;
                }
            }
        }
        return 0;
    }
};