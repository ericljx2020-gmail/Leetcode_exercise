class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        unordered_map<char,int> st1, st2;
        unordered_set<char> ss1, ss2;
        if (n != m) return false;
        for (int i = 0; i < n; i++){
            st1[word1[i]]++;
            st2[word2[i]]++;
            ss1.insert(word1[i]);
            ss2.insert(word2[i]);
        }

        for (auto c = 'a'; c <= 'z'; c++){
            bool f1 = false,f2 = false;
            if (ss1.find(c) != ss1.end()) f1 = true;
            if (ss2.find(c) != ss2.end()) f2 = true;
            if ((f1 && !f2) || (f2  && !f1)) return false;
        }
        vector<int> v1, v2;
        for (auto &[c, o] : st1){
            v1.push_back(o);
        }

        for (auto &[c, o] : st2){
            v2.push_back(o);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for (int i = 0; i < v1.size(); i++){
            if (v1[i] != v2[i]) return false;
        }

        return true;
    }
};