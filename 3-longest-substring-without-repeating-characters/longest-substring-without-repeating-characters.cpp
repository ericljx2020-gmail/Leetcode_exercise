class Solution {
public:

    bool check(int k, string s){ 
        unordered_map<char, bool> hash;
        int n = s.size();
        int tt = -1, hh = 0;
        int q[100005];
        for (int i = 0; i < n; i++) {
            if (hh <= tt && q[hh] < i-k+1) {
                hash[s[q[hh]]] = 0;
                hh++;
            }

            while (hh <= tt && hash[s[i]]) {
                // cout << s[q[hh]] << ' ';
                hash[s[q[hh++]]] = 0;
            }            
            // puts("");
            q[++tt] = i;
            hash[s[i]] = 1;
            // cout << hh << " " << tt << " " << k << "\n";
            if (tt-hh+1 >= k) return true;

        }
        return false;
    }

    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        int l = 1, r = n;
        bool flag = false;
        while (l < r){
            int mid = l + r + 1 >> 1;
            // puts("");
            if (check(mid, s)) {
                l = mid;
                cout << mid << " " << "True" << "\n";
            }else{
                r = mid-1;
                cout << mid << " " << "False" << "\n";
            }
        }


        return r;
    }
};