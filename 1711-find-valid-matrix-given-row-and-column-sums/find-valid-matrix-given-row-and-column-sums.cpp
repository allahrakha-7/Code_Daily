class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> matrix(rowSum.size(), vector<int> (colSum.size(),0));

        for (int i = 0; i < rowSum.size(); i++) 
        {
            for (int j = 0; j < colSum.size(); j++)
            {
                int value = min(rowSum[i], colSum[j]);
                matrix[i][j] = value;
                rowSum[i] -= value;
                colSum[j] -= value;
            } 
        }
        return matrix;
    }
};