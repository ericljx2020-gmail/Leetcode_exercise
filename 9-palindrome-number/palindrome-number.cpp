class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        vector<int> v;
        while (x){
            v.push_back(x % 10);
            x /= 10;
        }
        int l = 0, r = v.size()-1;
        while (l <= r){
            if (v[l] != v[r]) return false;
            l++, r--;
        }
        return true;
    }
};