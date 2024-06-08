class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        bool ones = true;
        int zeros = 0;
        int p = -1;
        for (int i = 0; i < n; i++){
            if (binary[i] == '0') {
                ones = false;
                zeros++;
                if (p == -1) p = i;
            }
        }
        if (ones) return binary;

        p += zeros-1;
        string res = "";
        for (int i = 0; i < n; i++){
            if (i == p) res += "0";
            else res += "1";
        }
        return res;
    }
};