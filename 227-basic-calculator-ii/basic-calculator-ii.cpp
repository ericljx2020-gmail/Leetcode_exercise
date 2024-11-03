class Solution {
public:
    unordered_map<char, int> pr;
    stack<char> op;
    stack<int> nums;
    int calculate(string s) {
        int n = s.size();
        pr['+'] = pr['-'] = 1, pr['*'] = pr['/'] = 2;
        for (int i = 0; i < n; i++){
            if (s[i] == ' ') continue;
            else if (s[i] == '(') {
                op.push(s[i]);
            }else if (s[i] == ')'){
                while (op.size() && op.top() != '('){
                    eval();
                }
            }else if (isdigit(s[i])){
                int j = i;
                int cur = 0;
                while (j < s.size() && isdigit(s[j])){
                    cur = cur * 10 + (s[j] - '0');
                    j++;
                }
                i = j-1;
                nums.push(cur);
            }else{
                while (op.size() && pr[op.top()] >= pr[s[i]]){
                    eval();
                }
                op.push(s[i]);
            }
        }
        while (op.size()){
            eval();
        }
        return nums.top();
    }

    void eval(){
        char o = op.top(); op.pop();
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();

        if (o == '+') nums.push(a+b);
        if (o == '-') nums.push(a-b);
        if (o == '*') nums.push(a*b);
        if (o == '/') nums.push(a/b);
    }

};