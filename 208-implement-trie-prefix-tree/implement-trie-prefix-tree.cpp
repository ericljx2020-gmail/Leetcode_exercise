class Trie {
public:

    struct Node{
        Node * son[26];
        bool is_end;

        Node(){
            is_end = false;
            for (int i = 0; i < 26; i++){
                son[i] = NULL;
            }
        }
    }* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        auto p = root;
        for (auto c : word){
            int s = c - 'a';
            if (!p -> son[s]) p -> son[s] = new Node();
            p = p -> son[s];
        }
        p -> is_end = true;
    }
    
    bool search(string word) {
        auto p = root;
        for (auto c : word){
            int s = c - 'a';
            if (!p -> son[s]) return false;
            p = p -> son[s];
        }
        return p -> is_end;
    }
    
    bool startsWith(string prefix) {
        auto p = root;
        for (auto c : prefix){
            int s = c - 'a';
            if (!p -> son[s]) return false;
            p = p -> son[s];
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