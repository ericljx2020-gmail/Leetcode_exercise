class Solution {
public:

    string decodes(string s) {
        int cnt = 0;
        char p = 's';
        string res = "";
        for (auto c : s) {
            if (c != p){
                if (p != 's'){
                    char t = cnt + '0';
                    res += t;
                    res += p;
                }
                p = c;
                cnt = 1;
            }else{
                cnt++;
            }
        }
        if (p != 's'){
            char t = cnt + '0';
            res += t;
            res += p;
        }
        return res;
    }

    string countAndSay(int n) {
        if (n == 1) return "1";
        return decodes(countAndSay(n-1));
    }
};