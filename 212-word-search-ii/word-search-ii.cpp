class Solution {
public:
    struct Node{
        int id;
        Node* son[26];
        Node(){
            id = -1;
            for (int i = 0; i < 26; i++) son[i] = NULL;
        }
    }*root;

    void insert(string word, int id) {
        auto p = root;
        for (auto c : word) {
            auto u = c - 'a';
            if (!p -> son[u]) p -> son[u] = new Node();
            p = p -> son[u]; 
        }
        p -> id = id;
    }

    vector<vector<char>> g;
    unordered_set<int> st;
    vector<string> res;
    int n,m;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size(), m = board[0].size();
        g = board;
        root = new Node();
        for (int i = 0; i < words.size(); i++){
            insert(words[i], i);
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                auto u = g[i][j] - 'a';
                if (root -> son[u]){
                    dfs(i,j,root -> son[u]);
                }
            }
        }

        for (auto c : st) res.push_back(words[c]);
        return res;
    }
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    void dfs(int x, int y, Node* p){ 
        if (p -> id != -1) st.insert(p -> id);
        auto t = g[x][y];
        g[x][y] = '.';

        for (int i = 0; i < 4; i ++){
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] != '.'){
                auto u = g[a][b] - 'a';
                if (p -> son[u]){
                    dfs(a,b,p -> son[u]);
                }
            }
        }
        g[x][y] = t;
    }

};