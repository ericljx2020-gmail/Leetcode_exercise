class Solution {
public:
    unordered_map<char, int> prior = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
    };

    stack<int> nums;
    stack<char> op;

    int calculate(string s) {
        int n = s.size();

        for (int i = 0; i < n; i++){
            auto c = s[i];
            if (c == ' ') continue;
            if (isdigit(c)){
                int j = i+1;
                int u = c-'0';
                while (j < n && s[j] != ' ' && isdigit(s[j])) u = u * 10 + (s[j++] - '0');
                nums.push(u);
                i = j-1;
            }else{
                char cur = s[i];
                while (op.size() && prior[op.top()] >= prior[cur]){
                    calc();
                }
                op.push(s[i]);
            }
        }
        while (op.size()){
            calc();
        }
        return nums.top();
    }

    void calc() {
        auto oper = op.top(); op.pop();
        int a = nums.top(); nums.pop();
        int b = nums.top(); nums.pop();
        cout << a << " " << b << "\n";

        if (oper == '+') nums.push(a + b);
        else if (oper == '-') nums.push(b-a);
        else if (oper == '/') nums.push(b / a);
        else if (oper == '*') nums.push(a * b);
        return;
    }

};