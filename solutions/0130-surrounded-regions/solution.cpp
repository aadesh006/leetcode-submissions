class Solution {
private:
    void markIndices(vector<vector<char>>& board, int r, int c){
        int rows = board.size();
        int cols = board[0].size();

        if(r >= rows || c >= cols || c < 0 || r < 0 || board[r][c] != 'O') return;

        board[r][c] = 'A';
        markIndices(board, r+1, c);
        markIndices(board, r-1, c);
        markIndices(board, r, c-1);
        markIndices(board, r, c+1);
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();

        for(int i=0 ; i<rows; i++){
            if(board[i][0] == 'O') markIndices(board, i, 0);
            if(board[i][cols-1] == 'O') markIndices(board, i, cols-1);
        }

        for(int j=0; j<cols; j++){
            if(board[0][j] == 'O') markIndices(board, 0, j);
            if(board[rows-1][j] == 'O') markIndices(board, rows-1, j);
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
};

