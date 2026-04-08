class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {0};
        bool cols[9][9] = {0};
        bool blocks[9][9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.')
                    continue;

                int val = board[r][c] - '1';

                int box_index = (r / 3) * 3 + (c / 3);

                if (rows[r][val] || cols[c][val] || blocks[box_index][val])
                    return false;

                rows[r][val] = 1;
                cols[c][val] = 1;
                blocks[box_index][val] = 1;
            }
        }

        return true;
    }
};
