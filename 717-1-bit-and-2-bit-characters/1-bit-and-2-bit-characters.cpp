class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() == 1) return bits[0] == 0;
        if (bits.size() && bits[bits.size()-1] == 1) return false;
        int n = bits.size();
        vector<vector<int>> f(n, vector<int> (2, 0));
        // f[i][0]表示第i个字符作为单可不可以
        // f[i][1]表示第i个字符作为双可不可以
        f[0][0] = bits[0] == 0;
        f[0][1] = false;
        f[1][0] = bits[1] == 0;
        f[1][1] = ((bits[0] == 1 && bits[1] == 0) || (bits[0] == 1 && bits[1] == 1));
        for (int i = 2; i < n; i++){
            f[i][0] = (f[i-1][1] | f[i-1][0]) && (bits[i] == 0);
            f[i][1] = (f[i-2][1] | f[i-2][0]) && ((bits[i-1] == 1 && bits[i] == 0) || (bits[i-1] == 1 && bits[i] == 1));
        }
        return f[n-1][0] && !f[n-1][1];
    }
};