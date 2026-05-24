
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;


        invertTree(root->left);
        invertTree(root->right);

        auto temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};
