/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> q1,q2;
        int idx = 1;
        q1.push(root);
        while (idx) {
            if (idx & 1){
                while (q1.size()) {
                    auto p = q1.front();
                    q1.pop();

                    if (q1.size()) p -> next = q1.front();
                    else p -> next = NULL;
                    if (p -> left) q2.push(p -> left);
                    if (p -> right) q2.push(p -> right);
                }
                if (q2.empty()) break;
            }else{
                while (q2.size()) {
                    auto p = q2.front();
                    q2.pop();

                    if (q2.size()) p -> next = q2.front();
                    else p -> next = NULL;
                    if (p -> left) q1.push(p -> left);
                    if (p -> right) q1.push(p -> right);
                }
                if (q1.empty()) break;
            }
            idx++;
        }
        return root;
    }
};