class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> res(queries.size(), -1);
        long long base = 1;
        for (int i = 0; i < (intLength-1) / 2; i++){
            base *= 10;
        }
        for (int i = 0; i < queries.size(); i++){
            if (queries[i] <= 9 * base){
                string s = to_string(base+queries[i]-1);
                if (intLength & 1){
                    string t = s.substr(0, s.size()-1);
                    reverse(t.begin(), t.end());
                    s += t;
                }else{
                    string t = s;
                    reverse(t.begin(), t.end());
                    s += t;
                }
                res[i] = stoll(s);
            }
        }
        return res;
    }
};