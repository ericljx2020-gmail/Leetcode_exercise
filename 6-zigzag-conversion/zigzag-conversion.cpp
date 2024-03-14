class Solution {
public:
    string convert(string s, int n) {
        string res = "";
        for (int i = 0; i < n; i++){
            if (i == 0 || i == n-1){ 
                for (int j = i; j < s.size(); j += max(1,2*n-2)){
                    res += s[j];
                }
            }else{
                for (int j = i, v = 2*n-2-i; j < s.size() || v < s.size(); j += 2*n-2, v += 2*n-2){
                    if (j < s.size()) res += s[j];
                    if (v < s.size()) res += s[v];
                }
            }
        }

        return res;
    }
};