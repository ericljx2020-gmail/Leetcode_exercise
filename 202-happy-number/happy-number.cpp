class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> hash;
        hash[n] = 1;
        while (true) {
            n = decode(n);
            if (n == 1) return true;
            if (hash[n]) return false;
            hash[n] = 1;
        }
        return true;
    }

    int decode(int x) {
        int res = 0;
        while (x) {
            int c = x % 10;
            res += c*c;
            x /= 10;
        }
        return res;
    }
};