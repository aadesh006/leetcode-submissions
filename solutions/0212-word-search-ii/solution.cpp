struct TrieNode{
    unordered_map<char, TrieNode*>children;
    string word = "";
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode;
    }

    void insert(string input){
        TrieNode* current = root;
        for(char letter : input){
            if(current->children.find(letter) == current->children.end()){
                current->children[letter] = new TrieNode;
            }
            current = current->children[letter];
        }
         current->word = input;
    }
};

class Solution {
private: 
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* current, vector<string>& result){

        int rows = board.size();
        int cols = board[0].size();

        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] == '#') return;

        char temp = board[r][c];
        if(current->children.find(temp) == current->children.end()) return;
        current = current->children[temp];

        if (!current->word.empty()) {
            result.push_back(current->word);
            current->word = ""; 
        }

        board[r][c] = '#';
        dfs(board, r+1, c, current, result);
        dfs(board, r-1, c, current, result);
        dfs(board, r, c+1, current, result);
        dfs(board, r, c-1, current, result);
        board[r][c] = temp;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        if (board.empty() || board[0].empty()) return {};
        Trie trie;
        vector<string> result;
        for(const string& s : words){
            trie.insert(s);
        }

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, trie.root, result);
            }
        }

        return result;
    }
};
