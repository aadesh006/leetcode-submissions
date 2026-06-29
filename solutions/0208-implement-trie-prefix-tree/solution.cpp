struct TrieNode{
    unordered_map<char, TrieNode*>children;
    bool isEndofWord = false;
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* current = root;

        for(char letter : word){
            if(current->children.find(letter) == current->children.end()){
                current->children[letter] = new TrieNode;
            }
            current = current->children[letter];
        }
        current->isEndofWord = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;

        for(char letter : word){
            if(current->children.find(letter) == current->children.end()){
                return false;
            }
            current = current->children[letter];
        }

        return current->isEndofWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;

        for(char letter : prefix){
            if(current->children.find(letter) == current->children.end()){
                return false;
            }
            current = current->children[letter];
        }

        return true;       
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
