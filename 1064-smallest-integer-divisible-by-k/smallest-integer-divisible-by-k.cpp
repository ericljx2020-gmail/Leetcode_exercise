class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k == 1) return 1;
        int x = 1;
        unordered_map<int, bool> hash;
        hash[1] = 1;
        int n = 1;
        while (true){
            x = (x * 10 + 1) % k;
            n++;
            if (x == 0) return n;
            if (hash[x]) return -1;
            hash[x] = 1;
        }
    }
};