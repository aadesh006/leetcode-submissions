class Solution {
private:
    bool findWord(vector<vector<char>>& board, string& word, int index,int r, int c){
        if (index == word.length()) return true;
        
        int rows = board.size();
        int cols = board[0].size();

        if(r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[index]){
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = findWord(board, word, index + 1, r - 1, c) ||
                     findWord(board, word, index + 1, r + 1, c) ||
                     findWord(board, word, index + 1, r, c - 1) ||
                     findWord(board, word, index + 1, r, c + 1);
        board[r][c] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        if(board.empty() || word.empty()) return false;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (findWord(board, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
