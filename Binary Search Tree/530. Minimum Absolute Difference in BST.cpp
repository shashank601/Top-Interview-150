
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


=======

dfs(root->right, root->val, ans);

You are thinking:

"I already passed current value, so why need reference?"
Because only the RIGHT subtree gets that updated value.
The parent stack frame itself does not change.



Now return back upward.
At parent node 3:
its local prev is STILL -1.


Why?

Because node 1 modified only its own copy.
So when parent processes:
root->val - prev
it becomes:

3 - (-1) <-- wrong

========

the "previous node" is not local to a subtree.
It is global traversal state.
That is why reference is needed.


so like imagine a tree 

that has just left nodes  so right dfs() call return null no impact on prev so now root sees that right prev 
