class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transpose
        // Then reverse rows
        for(int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix[0].size(); j++) {
                // Get triangular, shift by one right
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        printf("\n\n");

        for(auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};
