class Solution {
public:
    string fractionToDecimal(int a, int b) {
        double neg = (double) a / b;
        string s = "";
        long long c = (long long)a / b;
        s += to_string(c);
        if (a-c*b == 0) return s;
        s += '.';
        unordered_map<long long, long long> hash;
        // int dtpos = s.size();
        if (neg < 0 && s[0] != '-') s = '-'+ s;
        hash[a] = s.size();

        c = a-c*b;
        b = abs(b);
        c = abs(c);
        // cout << "c: " << c << '\n';
        int idx = 1;
        bool flag = false;
        while (idx){
            c *= 10;
            while (c / b == 0){
                c *= 10;
                s += '0';
            }
            cout << c << " ";
            s += to_string(c / b);
            c -= c/b*b;
            if (hash[c]){
                flag = true;
                break;
            }
            hash[c] = s.size();
            if (c == 0){
                return s;
            }
            idx++;
        }
        if (flag){
            s = s.substr(0,hash[c]) + '(' + s.substr(hash[c]) + ')';
        }

        return s;
    }
};