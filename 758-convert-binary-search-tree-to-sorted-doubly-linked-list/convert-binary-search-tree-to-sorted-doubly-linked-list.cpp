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
    Node* first = NULL;
    Node* last = NULL;
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        dfs(root);
        first -> left = last;
        last -> right = first;
        return first;
    }

    void dfs(Node* p){
        if (!p) return;
        dfs(p -> left);
        if (last){
            last -> right = p;
            p -> left = last;
        }else{
            first = p;
        }
        last = p;
        dfs(p -> right);
    }
};