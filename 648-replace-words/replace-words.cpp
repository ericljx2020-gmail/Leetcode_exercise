class Solution {
public:
    string replaceWords(vector<string>& dictionary, string s) {
        unordered_map<string, bool> hash;
        for (auto d : dictionary) hash[d] = true;
        string res = "";
        int j = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' '){
                res += s.substr(j, i-j) + " ";
                j = i+1;
                continue;
            }
            string c = s.substr(j, i-j+1);
            if (hash[c]){
                res+=c+" ";
                while (i < s.size() && s[i] != ' '){
                    i++;
                }
                j = i+1;
            }
        }
        if (j < s.size()){
            res += s.substr(j) + " ";
        }
        res.pop_back();
        return res;
    }
};