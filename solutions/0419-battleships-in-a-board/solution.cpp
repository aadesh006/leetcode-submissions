class Solution {
private:
    void dfs(vector<vector<char>>& board, int r, int c){
        if(board.empty()) return;
        int rows = board.size();
        int cols = board[0].size();

        if(r < 0 || c< 0|| r>=rows|| c>=cols || board[r][c] != 'X') return;
        board[r][c] = '.';

        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int shipCount =0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j] == 'X'){
                    dfs(board, i, j);
                    shipCount++;
                }
            }
        }
        return shipCount;
    }
};
