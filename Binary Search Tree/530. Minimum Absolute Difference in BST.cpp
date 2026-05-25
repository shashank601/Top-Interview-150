
class Solution {
public:
    void dfs(TreeNode* root, int& prev, int& ans) {
        if (!root) return;

        dfs(root->left, prev, ans);
        
        if (prev != - 1) 
            ans = min(ans, root->val - prev);

        prev = root->val;
        dfs(root->right, prev, ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int prev = -1;
        dfs(root, prev, ans);

        return ans;


    }
};


=======

void f(int x) {
    x = 10;
}

int main() {

  int a = 5;
    f(a);

    cout << a;
}


basically if i want to change a value of some older pushed stack frame withou unncecrary data transition then pass by ref helps

prev = root->val;
inside deepest recursion updates the shared variable seen by all callers.
