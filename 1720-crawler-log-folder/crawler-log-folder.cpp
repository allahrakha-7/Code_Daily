class Solution {
public:
    int minOperations(vector<string>& logs) {
        int mainFolder = 0;

        for (const string& log : logs)
        {
            if (log == "../")
            {
                if (mainFolder > 0)
                {
                    mainFolder--;
                }
            } else 
                if (log != "./")
                {
                mainFolder++;
                }
            }
        return mainFolder;
    }
};