class Solution {
public:

    bool check(string a){
        if (a.size() == 0) return false;
        //check digit
        for (int i = 0; i < a.size(); i++){
            if (a[i] > '9' || a[i] < '0') return false;
        }

        //check leading zero
        if (a[0] == '0' && a.size() > 1) return false;

        //check value
        if (a.size() > 3) return false;
        int tmp = 0;
        for (int i = 0; i < a.size(); i++){
            int c = a[i] - '0';
            tmp *= 10;
            tmp += c;
        }
        if (tmp > 255) return false;
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if (n > 12) return {};
        vector<string> ans;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                for (int k = j+1; k < n; k++){
                    string a = s.substr(0, i);
                    string b = s.substr(i, j-i);
                    string c = s.substr(j, k-j);
                    string d = s.substr(k);
                    if (check(a) && check(b) && check(c) && check(d)){
                        string cur = a+'.'+b+'.'+c+'.'+d;
                        ans.push_back(cur);
                    }
                    
                }
            }
        }
        return ans;
    }
};