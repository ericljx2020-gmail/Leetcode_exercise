class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int cur = 0;
        vector<int> hash(32, -2);
        hash[0] = -1;
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == 'a'){
                cur ^= 1;
            }else if (s[i] == 'e'){
                cur ^= 2;
            }else if (s[i] == 'i'){
                cur ^= 4;
            }else if (s[i] == 'o'){
                cur ^= 8;
            }else if (s[i] == 'u'){
                cur ^= 16;
            }
            if (hash[cur] == -2){
                //前面没出现过
                hash[cur] = i;
            }else{
                ans = max(ans, i-hash[cur]);
            }
        }
        return ans;
    }
};