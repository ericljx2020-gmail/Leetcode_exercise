class Trie {
public:

    struct Node{
        Node* son[26];
        bool is_end;

        Node(){
            for (int i = 0; i < 26; i++) son[i] = NULL;
            is_end = false;
        }
    }*root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        auto p = root;
        for (int i = 0; i < word.size(); i++){
            int c = word[i] - 'a';
            if (!p->son[c]) p -> son[c] = new Node();
            p = p -> son[c];
        }
        p->is_end = true;
    }
    
    bool search(string word) {
        auto p = root;
        for (int i = 0; i < word.size(); i++){
            int c = word[i] - 'a';
            if (!p -> son[c]) return false;
            p = p->son[c];
        }
        return p->is_end;
    }
    
    bool startsWith(string prefix) {
        auto p = root;
        for (int i = 0; i < prefix.size(); i++){
            int c = prefix[i] - 'a';
            if (!p->son[c]) return false;
            p = p -> son[c];
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