class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char, int> hash;
        unordered_set<char> st;
        for (auto c : s){
            hash[c]++;
            st.insert(c);
        }
        int res = 0;
        bool flag = 0;
        for (auto c : st) {
            if (hash[c] & 1){
                flag = 1;
                res += hash[c]-1;
            }else{
                res += hash[c];
            }
        }
        if (!flag)return res;
        return res+1;
    }
};