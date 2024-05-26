class Solution {
public:
    int minSwaps(string s) {
        int c0 = 0, c1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') c1++;
            if (s[i] == '0') c0++;
        }
        int res1 = 0;
        int res2 = 0;
        int res3 = 0;
        if (abs(c1-c0) > 1) return -1;
        cout << c1 << " " << c0 << " \n";
        for (int i = 0; i < s.size(); i += 2) {
            if (s[i] != '0') res1++;
        }
        for (int i = 0; i < s.size(); i += 2){ 
            if (s[i] != '1') res2++;
        }
        // char c = s[0];
        // for (int i = 0; i < s.size(); i += 2) {
        //     if (s[i] != c) res3++;
        // }

        if (c1 > c0) return res2;
        if (c0 > c1) return res1;
        return min(res2, res1);
    }
};