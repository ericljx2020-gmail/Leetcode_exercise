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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        /*
        * 看一颗子树，每一次递归维护两个值{最大深度，当前子树里最深点的lca}
        * 如果左右子树的深度分别为 dl, dr. 那么可以分情况考虑
        * 1. 如果dl == dr说明两边都有最深的点，那么lca一定是当前点
        * 2. 如果dl > dr说明左边子树更深，那么右边一定没有最深的点，所以lca一定在左子树里
        * 3. 如果dr > dl说明右子树更深，则lca一定在右边
        */

        return dfs(root).second;
    }

    pair<int, TreeNode*> dfs(TreeNode* p) {
        if (!p) return {0, NULL};
        auto l = dfs(p -> left), r = dfs(p -> right);
        if (l.first == r.first) return {l.first+1, p};
        if (l.first > r.first) return {l.first+1, l.second};
        return {r.first+1, r.second};
    }
};