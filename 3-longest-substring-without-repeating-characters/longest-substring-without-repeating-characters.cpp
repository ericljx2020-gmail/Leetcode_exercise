class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 1, r = n;
        while (l < r){
            int mid = l + r + 1 >> 1;
            cout << mid << "\n";
            if (check(mid,s)){
                //当前窗口size可以那么可以试一下更长的
                l = mid;
                cout << "OK" << "\n";
            }else{
                r = mid-1;
                cout << "Not" << "\n";
            }
            
        }

        return r;
    }

    bool check(int k, string s) {
        int q[50004];
        int tt = -1, hh = 0;
        int n = s.size();
        unordered_map<char, bool> hash;
        for (int i = 0; i < n; i++){
            if (hh <= tt && q[hh] < i-k+1){
                hash[s[q[hh++]]] = 0;
            }
            while (hh <= tt && hash[s[i]]){
                hash[s[q[hh++]]] = 0;
            }
            q[++tt] = i;
            hash[s[i]] = 1;
            if (tt - hh + 1 >= k) return true;
        }

        return false;
    }
};