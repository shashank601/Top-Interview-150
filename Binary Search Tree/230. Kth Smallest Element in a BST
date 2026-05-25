
class Solution {
public:
    int ans = INT_MIN;
    void g(TreeNode* root, int& k) {
        if (k == 0 || !root) return;
        g(root->left, k);
        k--;
        if (k == 0) ans = root->val;
        g(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        g(root, k);
        return ans;
    }
};



==========

for follow up:
augment BST nodes with subtree sizes

this is called as Order Statistic Tree => BST + subtree counts
