/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* inverse(TreeNode* p){
        if (!p) return NULL;
        inverse(p -> left);
        inverse(p -> right);
        swap(p -> left, p -> right);
        return p;
    }

    bool isSame(TreeNode* p, TreeNode* q){
        if (!p && !q) return true;
        if(!p || !q || p->val != q->val) return false;
        return isSame(p -> left, q->left) && isSame(p->right, q->right);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        if (!root -> right && !root -> left) return true;
        if (!root -> right || !root -> left || root -> right -> val != root -> left -> val) return false;
        auto L = inverse(root -> left);
        auto R = root -> right;
        return isSame(L,R);
    }
};