class Solution {
public:
    struct Node{
        Node* sons[26];
        bool is_end;

        Node(){
            is_end = false;
            for (int i = 0; i < 26; i++) sons[i] = NULL;
        }
    }* root;

    void insert(string s){
        auto u = root;
        for (auto c : s){
            if (u -> sons[c-'a']){
                u = u -> sons[c-'a'];
            }else{
                u -> sons[c-'a'] = new Node();
                u = u -> sons[c-'a'];
            }
        }
        u -> is_end = true;
    }

    string find(string s){
        auto u = root;
        string ret = "";
        for (auto c : s){
            if (!u -> sons[c-'a']) return "";
            u = u -> sons[c-'a'];
            ret += c;
            if (u -> is_end){
                return ret;
            }
        }
        if (u -> is_end) return ret;
        return "";
    }

    string replaceWords(vector<string>& dictionary, string s) {
        //trie做法
        int n = s.size();
        root = new Node();
        for (auto d : dictionary){
            insert(d);
        }
        int j = 0;
        vector<string> v;
        for (int i = 0; i < n; i++){
            if (s[i] == ' '){
                v.push_back(s.substr(j, i-j));
                j = i+1;
            }
        }
        v.push_back(s.substr(j));
        // for (auto vv : v) cout << vv << " ";
        string res = "";
        for (auto ss : v){
            auto r = find(ss);
            if (r != ""){
                res += r + " ";
            }else{
                res += ss + " ";
            }
        }
        res.pop_back();
        return res;
        // return "";
    }
};