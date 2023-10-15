class Solution {
public:

    bool check(int l, string a, string b){
        string cur = a.substr(0,l);
        for (int i = 0; i < a.size(); i++){
            if (a[i] != cur[i % cur.size()]) return false;
            // cout << a[i%cur.size()] << " " << cur[i % cur.size()] << "\n";
        }
        for (int i = 0; i < b.size(); i++){
            if (b[i] != cur[i % cur.size()]) return false;
        }
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<int>div;
        for (int i = 1; i <= min(n,m); i++){
            if (n % i == 0 && m % i == 0) div.push_back(i);
        }
        for (int i = div.size()-1; i >= 0; i--){
            int c = div[i];
            if (check(c, str1, str2)){
                return str2.substr(0,c);
            }
        }
        return "";
    }
};