class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Convert to 2d array
        vector<vector<int>> matrix(9, vector<int>(9));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    matrix[i][j] = static_cast<int>(board[i][j]);
                }
                else {
                    matrix[i][j] = -1;
                }
            }
        }
        //row check
        for(auto row : matrix) {
            if(!rowCheck(row)){
                return false;
            }
        }
        //col check
        for(int i = 0; i < 9; i++) {
            //construct row;
            vector<int> nums(9);
            for(int j = 0; j < 9; j++) {
                nums[j] = matrix[j][i];
            }
            //do check
            if(!rowCheck(nums)){
                return false;
            }
        }
        //3x3 grid check 
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                if(!gridCheck(matrix, i, j)){
                    return false;
                }
            }
        }

        return true;
        
    }
    bool rowCheck(vector<int> nums) {
        unordered_set<int> setOfNums;
        for(int num : nums) {
            if(num != -1 && setOfNums.contains(num)){
                return false;
            }
            setOfNums.insert(num);
        }
        return true;
    }

    bool gridCheck(vector<vector<int>> matrix, int startRow, int startCol) {
        unordered_set<int> setOfNums;
        for(int row = startRow; row < startRow + 3; row++){
            for(int col = startCol; col < startCol + 3; col++) {
                int num = matrix[row][col];
                if(num != -1 && setOfNums.contains(num)){
                    return false;
                }
                setOfNums.insert(num);
            }
        }
        return true;
    }

};
