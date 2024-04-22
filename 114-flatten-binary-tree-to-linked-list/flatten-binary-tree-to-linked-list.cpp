class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        
        vector<int> v;
        helperFlatten(root, v);
        
        TreeNode* ptr = root;
        for (int i = 1; i < v.size(); i++) {
            ptr->left = nullptr;
            ptr->right = new TreeNode(v[i]);
            ptr = ptr->right;
        }
    }

    void helperFlatten(TreeNode* root, vector<int>& v) {
        if (!root) return;
        
        v.push_back(root->val);
        helperFlatten(root->left, v);
        helperFlatten(root->right, v);
    }
    
};