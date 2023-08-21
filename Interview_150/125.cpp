class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (l <= r){
            if ((s[l] > 'Z' || s[l] < 'A') && (s[l] > 'z' || s[l] < 'a') && (s[l] > '9' || s[l] < '0')) l++;
            else if ((s[r] > 'Z' || s[r] < 'A') && (s[r] > 'z' || s[r] < 'a') && (s[r] > '9' || s[r] < '0')) r--;
            else if (s[l] <= 'Z' && s[l] >= 'A'){
                s[l] = 'a'+(s[l]-'A');
            }else if (s[r] <= 'Z' && s[r] >= 'A'){
                s[r] = 'a'+(s[r]-'A');
            }else{
                if (s[l] != s[r]) return false;
                cout << s[l] << " " << s[r] << endl;
                l++;
                r--;
            }
        }

        return true;
    }
};