class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int n = s.size();
        unordered_map<char, int> ss, tt;
        for (int i = 0; i < s.size(); i++) {
            ss[s[i]]++;
            tt[t[i]]++;
        }
        // cout << ss['0'] << " " << tt['0'];
        if (ss['1'] > tt['1']) {
            // 11 -> 10
            while (ss['1'] != tt['1']) {
                ss['1'] -= 2;
                if (ss['1'] < 0) return false;
                ss['1'] ++;
                ss['0'] ++;
            }
        }else if (ss['0'] > tt['0']){
            // 01 -> 11
            while (ss['0'] != tt['0']) {
                ss['0']--;
                ss['1']--;
                if (ss['0'] < 0 || ss['1'] < 0) return false;
                ss['1'] += 2;
            }
        }
        return true;
    }
};