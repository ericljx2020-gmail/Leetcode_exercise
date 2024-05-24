class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int hl = 0, hr = 0;
        for (int i = 0; i < 32; i++){
            if (left >> i & 1) hl = max(hl, i);
            if (right >> i & 1) hr = max(hr, i);
        }
        if (hl != hr) return 0;
        cout << hl << " " << hr;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int c = left >> i & 1;
            if (c != (right >> i & 1)) break;
            res += c << i;
        }
        return res;
    }
};

// 0101
// 0110
// 0111
// 1000