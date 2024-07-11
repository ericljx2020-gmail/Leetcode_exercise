class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int res = 0;
        for (int i = 0; i + k - 1 < s.size(); i++){
            string ss = s.substr(i, k);
            int t = stoi(ss);
            if (t == 0) continue;
            res += (num % t == 0);
        }
        return res;
    }
};