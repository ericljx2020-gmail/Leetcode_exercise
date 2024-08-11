class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return check(a,b) || check(b,a);
    }

    bool check(string a, string b){
        int i = 0, j = b.size()-1;
        while (i < j && a[i] == b[j]){
            i++;
            j--;
        }
        return is_palindrome(a, i, j) || is_palindrome(b, i, j);
    }

    bool is_palindrome(string a, int i, int j){
        while (i < j){
            if (a[i] != a[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};