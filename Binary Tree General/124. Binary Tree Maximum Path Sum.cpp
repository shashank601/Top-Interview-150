class Solution {
public:
    int ans = INT_MIN;

    int g(TreeNode* root) {
        if (!root) return 0;

        int l = g(root->left);
        int r = g(root->right);

        ans =  max({ans, l + r + root->val, l + root->val, r + root->val, root->val});
        

        return max({l + root->val, r + root->val, root->val});
    }
    int maxPathSum(TreeNode* root) {
        g(root);

        return ans;   
    }
};

=====

very similar to diameter of bt
only send +ive values upward
