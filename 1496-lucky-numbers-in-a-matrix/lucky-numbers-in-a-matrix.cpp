class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> luckyNumbers;
        
        for (int i = 0; i < matrix.size(); ++i) {
            int rowMin = matrix[i][0];
            int colIndex = 0;
            
            for (int j = 1; j < matrix[i].size(); ++j) {
                if (matrix[i][j] < rowMin) {
                    rowMin = matrix[i][j];
                    colIndex = j;
                }
            }
            
            bool isMaxInCol = true;
            for (int k = 0; k < matrix.size(); ++k) {
                if (matrix[k][colIndex] > rowMin) {
                    isMaxInCol = false;
                    break;
                }
            }

            if (isMaxInCol) {
                luckyNumbers.push_back(rowMin);
            }
        }
        
        return luckyNumbers;
    }
};
