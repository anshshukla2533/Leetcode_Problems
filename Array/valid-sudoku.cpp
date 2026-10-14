class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char val = board[r][c];
                if (val == '.') continue;
                
                // Check row and column
                for (int i = 0; i < 9; ++i) {
                    if (i != c && board[r][i] == val) return false;
                    if (i != r && board[i][c] == val) return false;
                }
                
                // Check 3x3 sub-box
                int startRow = (r / 3) * 3;
                int startCol = (c / 3) * 3;
                for (int dr = 0; dr < 3; ++dr) {
                    for (int dc = 0; dc < 3; ++dc) {
                        int currR = startRow + dr;
                        int currC = startCol + dc;
                        if ((currR != r || currC != c) && board[currR][currC] == val) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};