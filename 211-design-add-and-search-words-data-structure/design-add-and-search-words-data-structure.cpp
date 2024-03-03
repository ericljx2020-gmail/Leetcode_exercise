class WordDictionary {
public:

    struct Node {
        Node* son[26];
        bool is_end;

        Node() {
            for (int i = 0; i < 26; i++) son[i] = NULL;
            is_end = false;
        }
    }*root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        auto p = root;
        for (auto c: word) {
            int u = c - 'a';
            if (!p -> son[u]) p -> son[u] = new Node();
            p = p -> son[u]; 
        }

        p -> is_end = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }

    bool dfs(Node* p, string word, int i){
        if (i == word.size()) return p -> is_end;
        if (word[i] == '.') {
            for (int j = 0; j < 26; j++){
                if (p->son[j] && dfs(p->son[j], word, i+1)){
                    return true;
                }
            }
            return false;
        }else{
            int u = word[i] - 'a';
            if (!p->son[u]) return false;
            return dfs(p->son[u], word, i+1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */