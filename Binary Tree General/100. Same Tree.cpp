
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            if (p || q) {
                return false; 
            } else {
                return true;
            }
        }

        if (p->val == q->val && isSameTree(p->left,q->left)) {               <-- eqv to: a == b && g() && g()
            return isSameTree(p->right,q->right);
        }
        return false;
    }
};
