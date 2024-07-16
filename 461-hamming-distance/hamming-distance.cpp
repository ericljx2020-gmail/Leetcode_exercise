class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        int d = 0;
        for (int i = 0; i < 32; i++){
            d += x >> i & 1;
        }
        return d;
    }
};