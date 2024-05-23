class Solution {
public:
    int compareVersion(string version1, string version2) {
        int st = 0;
        vector<string> v1, v2;
        for (int i = 0; i < version1.size(); i++) {
            if (version1[i] == '.'){
                v1.push_back(version1.substr(st, i-st));
                st = i+1;
                // cout << v1[v1.size()-1] << " ";
            }
        }
        v1.push_back(version1.substr(st));
        // puts("");
        st = 0;
        for (int i = 0; i < version2.size(); i++){
            if (version2[i] == '.'){
                v2.push_back(version2.substr(st, i-st));
                st = i+1;
                // cout << v2[v2.size()-1] << " ";
            }
        }
        v2.push_back(version2.substr(st));
        
        for (int i = 0; i < v1.size(); i++){
            v1[i] = erp(v1[i]);
        }
        for (int i = 0; i < v2.size(); i++){
            v2[i] = erp(v2[i]);
        }
        while (v2.size() && v2[v2.size()-1] == "0") {
            v2.pop_back();
        }
        while (v1.size() && v1[v1.size()-1] == "0") {
            v1.pop_back();
        }

        // for (auto v : v1) cout << v << " ";
        // puts("");
        // for (auto v : v2) cout << v << " ";
        // cout << v2.size();
        for (int i = 0; i < min(v2.size(), v1.size()); i++) {
            if (stoi(v1[i]) < stoi(v2[i])) return -1;
            else if (stoi(v1[i]) > stoi(v2[i])) return 1;
        }
        if (v1.size() == v2.size()) return 0;
        if (v1.size() < v2.size()) return -1;
        else return 1;

        return 0;
    }

    string erp(string s) {
        int idx = 0;
        while (idx < s.size() && s[idx] == '0'){
            idx++;
        }
        if (idx == s.size()) return "0";
        s = s.substr(idx);
        return s;
    }
};