class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // understand this trick
        int row[9] = {0};
        int col[9] = {0};
        int box[9] = {0};

        for(int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // Remember its a char so '', not ""
                // regular equality is fine
                char num = board[i][j];
                if(num == '.'){
                    continue;
                }
                // int num = board[]
                // The first trick:
                // &, |, ^, ~, <<, >>

                // Also know integer division exists in c++ like c
                int boxNum = (i / 3) * 3 + (j / 3);
                // We can also leverage the fact that chars behave like ints, and the numbers 0 - 9 are next to each other
                int bitShift = num - '0';
                // we know the row and column, so we insert a one into the row, box, and col
                // First check if this number exists in the row, col, or box.
                // The trick here is to use the right shift operator to check the bit
                if((row[i] >> bitShift & 1) || (col[j] >> bitShift & 1) || (box[boxNum] >> bitShift & 1)) {
                    return false;
                }
                // If not then add it to the box, row col
                // Row
                row[i] |= 1 << bitShift;
                // Col
                col[j] |= 1 << bitShift;
                // Box (use the flattening trick), getting meta row and meta column
                box[boxNum] |= 1 << bitShift;
            }
        }        
        return true;
    // Weird thing about c++: if you ever get an error where it is weird (like its pointing to the a weird spot, try the loop body function)
    }
};
