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
    unordered_map<int, int> hash;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) hash[inorder[i]] = i;
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if (pl > pr) return nullptr;
        TreeNode* root = new TreeNode(preorder[pl]);              //前缀遍历中第一个是root
        int in_pos = hash[root -> val];  //当前根节点在inorder中的index，index左边的就是左子树
        root -> left = build(preorder, inorder, pl+1,pl+1+in_pos-1-il , il, in_pos-1);
        root -> right = build(preorder, inorder, pl+1+in_pos-1-il+1, pr, in_pos+1, ir);
        return root;
    }
};