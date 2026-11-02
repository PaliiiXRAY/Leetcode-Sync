class Trie {
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children[c - 'a']) {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return true;
    }
};