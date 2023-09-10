class Solution {
public:
    string addBinary(string a, string b) {
        int idx = 1;
        if (a.size() < b.size()) swap(a,b);         //let a.size() > b.size()
        int maxsize = a.size();
        int carry = 0;
        string ans = "";
        while (idx <= maxsize) {
            char ai = a[a.size()-idx];
            char bi = ((int)b.size() - idx) < 0 ? '0' : b[b.size()-idx];
            cout << ai << " " << bi << endl;
            if (ai == '1' && bi == '1' && carry == 1) ans += "1", carry = 1, puts("a");
            else if (ai == '1' && bi == '1') ans += "0", carry = 1, puts("b");
            else if ((ai == '1' || bi == '1') && carry == 1) ans += "0", carry = 1, puts("c");
            else if (ai == '1' || bi == '1') ans += "1", carry = 0;
            else if (carry)ans += "1", carry = 0;
            else ans += "0", carry = 0;
            cout << carry << endl;
            idx++;
        }
        if (carry) ans += "1";
        string res = "";
        for (int i = ans.size()-1; i >= 0; i--) res += ans[i];
        return res;
    }
};