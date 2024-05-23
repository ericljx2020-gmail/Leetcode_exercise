class Solution {
public:
    string convertToTitle(int n) {
        int k = 1;
        for (long long p = 26; p < n; p *= 26) {
            n -= p;
            k++;
        }

        n--;
        string s = "";
        while (k--) {
            s += (n % 26) + 'A';
            n /= 26;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};