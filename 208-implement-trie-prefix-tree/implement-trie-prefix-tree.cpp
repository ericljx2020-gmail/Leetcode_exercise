class Trie {
public:

    struct Node {
        Node* son[26];
        bool is_end;
        
        Node () {
            for (int i = 0; i < 26; i++) son[i] = NULL;
            is_end = false;
        }
    }*root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        auto p = root;
        for (auto c : word) {
            int a = c - 'a';
            if (!p -> son[a]) p -> son[a] = new Node();
            p = p -> son[a];
        }

        p -> is_end = true;
    }
    
    bool search(string word) {
        auto p = root;
        for (auto c : word){
            int a = c - 'a';
            if (!p -> son[a]) return false;
            p = p -> son[a];
        }

        return p -> is_end;
    }
    
    bool startsWith(string prefix) {
        auto p = root;
        for (auto c : prefix){
            int a = c - 'a';
            if (!p -> son[a]) return false;
            p = p -> son[a];
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