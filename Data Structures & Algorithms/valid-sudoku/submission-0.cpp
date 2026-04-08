class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Iterate rows
        for (auto row : board) {
            set<char> mp;
            for (char i : row) {
                if (i == '.')
                    continue;

                if (mp.find(i) != mp.end())
                    return false;

                mp.insert(i);
            }
        }

        // Iterate cols
        for (int i = 0; i < 9; ++i) {
            set<char> mp;
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.')
                    continue;

                if (mp.find(board[j][i]) != mp.end())   
                    return false;

                mp.insert(board[j][i]);
            }
        }

        // Iterate blocks
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                set<char> mp;
                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        if (board[i + r][j + c] == '.')
                            continue;

                        if (mp.find(board[i + r][j + c]) != mp.end())
                            return false;

                        mp.insert(board[i + r][j + c]);
                    }
                }
            }
        }

        return true;
    }
};
