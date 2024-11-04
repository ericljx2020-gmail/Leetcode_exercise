/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:

    stack<Node*> stk;

    Node* treeToDoublyList(Node* root) {
        if (!root) return root;

        auto it = root;
        while (it){
            stk.push(it);
            it = it -> left;
        }

        auto head = new Node(0);
        auto prev = head;
        Node* current;

        while (stk.size()){
            current = stk.top();
            stk.pop();

            prev -> right = current;
            current -> left = prev;
            prev = current;

            auto it = current -> right;
            while (it){
                stk.push(it);
                it = it -> left;
            }
        }

        head -> right -> left = current;
        current -> right = head -> right;

        return head -> right;
    }
};