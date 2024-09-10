class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        int n = secret.size();
        unordered_map<int, bool> st;
        unordered_map<char, int> hash;
        for (int i = 0; i < n; i++){
            if (secret[i] == guess[i]) {
                A++;
                st[i] = 1;
            }
        }

        for (int i = 0; i < n; i++){
            if (st[i]) continue;
            hash[secret[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (st[i]) continue;
            if (hash[guess[i]] > 0){
                B++;
                hash[guess[i]]--;
            }
        }
        string res = to_string(A) + 'A' + to_string(B) + 'B';
        return res;
    }
};